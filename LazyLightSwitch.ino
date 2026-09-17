#include <ESP32Servo.h>
#include <WiFi.h>
#include <WebServer.h>

Servo flipper;
WebServer server(80);

const char* ssid = "mywifissid";
const char* password = "mywifipassword";

const int servoPin = 18;
const int upAngle = 60;
const int downAngle = 140;

void setup() {
  Serial.begin(115200);

  flipper.setPeriodHertz(50);
  flipper.attach(servoPin, 500, 2400);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected. IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/up", []() {
    flipper.write(upAngle);
    server.send(200, "text/plain", "switch up");
  });

  server.on("/down", []() {
    flipper.write(downAngle);
    server.send(200, "text/plain", "switch down");
  });

  server.on("/angle", []() {
    if (server.hasArg("val")) {
      int a = server.arg("val").toInt();
      flipper.write(a);
      server.send(200, "text/plain", "moved to " + String(a));
    } else {
      server.send(400, "text/plain", "missing val parameter");
    }
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
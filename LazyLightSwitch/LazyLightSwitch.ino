#include <ESP32Servo.h>
#include <WiFi.h>
#include <WebServer.h>
#include <ESPmDNS.h>

Servo flipper;
WebServer server(80);

const char* ssid = "wifissd";
const char* password = "password";

// new update! set up static IP; example of how it would be written: IPAddress local_IP(8, 8, 8, 8); (sorry google)
IPAddress local_IP("put your desired static IP address here I don't want to doxx myself");
IPAddress gateway("put your gateway address here"); 
IPAddress subnet("subnet");
IPAddress dns("you get it");

// these angles worked for me but might not for you so play around with them
const int servoPin = 18;
const int upAngle = 60;
const int downAngle = 140;

void setup() {
  Serial.begin(115200);

  flipper.setPeriodHertz(50);
  flipper.attach(servoPin, 500, 2400);

  if (!WiFi.config(local_IP, gateway, subnet, dns)) {
    Serial.println("Static IP config FLOPPED!!");
  }
  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected. IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("lightswitch")) {
    Serial.println("Reachable at http://lightswitch.local");
  }

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
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();
    delay(5000);
    return;
  }
  server.handleClient();
}
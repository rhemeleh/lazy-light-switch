meow meow i cant wake up :(

Initial problem: I cannot wake up without an intense amount of light hitting my eyes, even if my alarm is at max volume. I bought a sunrise lamp that illuminates my bedside 30 minutes before my alarm goes off. Unfortunately, the sunrise lamp did not solve my problem; I still could not wake up. The idea behind this light switch flipper came to mind after almost not getting up in time for my shift :(

Idea: Make a remote-controlled device? that flips my bedroom's light switch the moment I wake up.

Functions:
1. The device turns my light on when my alarm rings to prevent me from falling asleep after I wake up briefly to turn my alarm off.
2. The device can also turn my light off when I need to leave my room.
3. The device can also turn my light on whenever I need it to, not just when I wake up.

Objectives:
1. The device does not manipulate my light when i do not want it to
2. The device can be remote controlled (from my bed!)

Constraints:
1. I do NOT want to touch my house's actual electrical wiring.
2. My light switch is very far away from any outlet; find a way to power the device.
3. I wish to only use what I currently have, because engineering is starting to cook me and I noticed I started requiring more time to wake up in the mornings. This is a pressing matter!!!

Here is a solution I came up with, after some pondering:

1. Since I do not want to touch my house's electrical network at all because I don't know what I am doing, to fulfill this requirement, I will design an attachment to my light switch. Thus, the device will flip the physical switch instead of making everyone in my neighbourhood lose power.
2. Since I want this device to be remote-controlled and my options are limited, I chose to use an ESP32 (I only have an Arduino R3 aside from a bazillion ESP32) to work on wifi. My phone is always connected to my home 2.4GHz wifi anyway because the 5G sucks for some reason. 


On September 15, the 3D printer I ordered finally arrived!! After months of being unable to start this project (school was closed and I was stuck at work), I immediately got to printing the parts. Thankfully, while I was researching and brainstorming, I found someone who had the same idea, so I used their 3D model: https://www.printables.com/model/505346-9g-servo-light-switch-flipper


<img width="3024" height="4032" alt="3d-printer" src="https://github.com/user-attachments/assets/5241059a-83f1-4b95-8bbc-d0416c98a48d" />
My printer starting the print!

After successfully printing the parts I needed (sidenote: I forgot to buy filament, so I printed these with the sample filament that came with my printer), I attached the 9g servo motor to the base using some tiny screws. 

<img width="3024" height="4032" alt="printed-parts" src="https://github.com/user-attachments/assets/aa695998-c66f-496f-87e1-d6e951853e64" />
The printed parts; everything went smoothly.

<img width="3024" height="4032" alt="servo-1" src="https://github.com/user-attachments/assets/e786cca2-8b87-49bf-89b6-57cd9ce9749e" />   <img width="3024" height="4032" alt="servo-2" src="https://github.com/user-attachments/assets/c38da551-0cf9-444f-b411-b45921e90b31" />
Some close-ups of how the servo is attached.

After assembling the build and uploading the code to my microcontroller, I tested some target angles to make the servo turn enough to flick my light switch. I did not have any soldering equipment at the time, so I stuck everything to a breadboard and taped it to my wall and called it a day. I saved the URLs for the up and down commands as shortcuts on my phone so I can turn my light on/off from a distance so long as I am connected to my home wifi. I also created shortcuts that turn my lights on when my final alarm of the morning rings. I need to feel like a deer caught in headlights to wake up. I also had a spare 10kmAh power bank that I now use to power the board overnight. 

<img width="3024" height="4032" alt="finalsetup" src="https://github.com/user-attachments/assets/96e5f1b3-fe63-4c19-b4f9-4eed6ba6a568" />
This was the final setup in October. 


November updates:

First off, my initial code did not assign a static IP address to my board, huge oversight on my part, but the more you learn I guess. Since I need to unplug the board from the power source to charge it when it runs out of power, another device in the house would sometimes steal the board's IP address, so I frequently had to go into ArduinoIDE to upload the code to the board again and it sucked because I would only notice that the IP address changed when my lights did not turn on in the morning and I would be running late again. To solve this issue, I added a snippet of code to assign a static address to my board. I've uploaded the newest version of the code that fixes the problem.

Also, my breadboard was sooo heavy that my tape would often give out and the board would fall off during the night. Of course, I would also only notice when I woke up in the morning and I was running late again! To solve this issue, I bought a soldering kit and an ESP32 mini to make the whole setup lighter. I will update if any issues arise again.

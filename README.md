Hello!



Here is my documentation for the lazy light switch.



Initial problem:

I cannot wake up without an intense amount of light hitting my eyes, even if my alarm is at max volume. I bought a sunrise lamp that illuminates my bedside 30 minutes before my alarm goes off.

Unfortunately, it did not solve my problem; I still could not wake up. The idea behind this light switch flipper came to mind after almost not getting up in time for my shift :(



Idea:

Make a remote-controlled device? That can flip my bedroom's light switch the moment I wake up.



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



Here is what IÕve came up with for now, after some pondering:

1. Since I do not want to touch my house's electrical network at all because I don't know what I am doing, to fulfill this requirement, I will design an attachment to my light switch. Thus, the device will flip the physical switch instead of making everyone in my neighbourhood lose power.
2. Since I want this device to be remote-controlled and my options are limited, I chose to use an ESP32 (I only have an Arduino R3 aside from a bazillion ESP32) to work on wifi. My phone is always connected to my home 2.4GHz wifi. 

Here is the walk through of my process. 

On September 15, the 3D printer I ordered finally arrived, so after months of being unable to start this project (school was closed and I was stuck at work), I immediately got to printing the parts. Thankfully, while I was researching and brainstorming, I found someone who had the same idea, so I used their 3D model: https://www.printables.com/model/505346-9g-servo-light-switch-flipper



After successfully printing the parts I needed (sidenote: I forgot to buy filament, so I printed these with the sample filament that came with my printer), I attached the 9g servo motor to the base using some tiny screws. 





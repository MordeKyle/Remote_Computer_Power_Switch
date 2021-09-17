# Remote_Computer_Power_Switch
 Allows you to remotely control the power switch and reset switch of a computer via an ESP8266 microcontroller and the Blynk Android or IOS app.

## Required Skills
 •Knowledge of the I/O pin header on a computers motherboard<br/>
 •Soldering
## Parts list:
 •Wemos D1 mini lite ESP8266 Microcontroller: https://www.amazon.com/dp/B07BK435ZW/<br/>
 •A proto board of any type: https://www.amazon.com/ElectroCookie-Solderable-Breadboard-Electronics-Gold-Plated/dp/B07ZYNWJ1S/<br/>
 •Octocouplers: https://www.amazon.com/dp/B01JG8EJVW/<br/>
 •Male to female jumper wires: https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/<br/>
 •Male Headers: https://www.amazon.com/Hotop-Pack-Single-Header-Connector/dp/B06XR8CV8P/<br/>
 •2x 220Ω resistors<br/>
 •1x 1KΩ resistor<br/>
 •Wire<br/>
 •Solder
 
## Libraries
 •BlynkSimpleEsp8266.h<br/>
 •ESP8266WiFi.h<br/>
 <img src="https://github.com/MordeKyle/Remote_Computer_Power_Switch/blob/main/Images/Libraries_to_install.png">
  
## Wiring Diagram
 <img src="https://github.com/MordeKyle/Remote_Computer_Power_Switch/blob/main/Images/Remote_Circuit.png">

## Blynk Setup
 See [THIS LINK](https://blynk.io/en/getting-started) for help getting started with Blynk.
### Blynk Layout
 This is where you will place you virtual buttons and a digital pin.<br/>
 <img src="https://github.com/MordeKyle/Remote_Computer_Power_Switch/blob/main/Images/Blynk_Layout.png" width=250>
### Virtual Reset Button
 This is a virtual button that will reset the computer. Set it as Virtual Pin 2 and use the following attributes on your button.<br/>
 <img src="https://github.com/MordeKyle/Remote_Computer_Power_Switch/blob/main/Images/Reset_Button_V2.png" width=250>
### Virtual Power Button
 This is a virtual button that will power on the computer. Set it as Virtual Pin 3 and use the following attributes on you button.<br/>
 <img src="https://github.com/MordeKyle/Remote_Computer_Power_Switch/blob/main/Images/Power_Button_V3.png" width=250>
### Digital Pin 2
 This is a physical pin on the Wemos. This will display whether pin D2 is being held HIGH or LOW and will tell you if the computer is on or off. Set it as a Value Display on D2 and use the following attributes below.<br/>
 <img src="https://github.com/MordeKyle/Remote_Computer_Power_Switch/blob/main/Images/D2.png" width=250>

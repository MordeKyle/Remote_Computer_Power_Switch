#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//Blynk authorization key and wifi information
//Remove the " completly
char auth[] = "YOUR BLYNK AUTH CODE HERE";
char ssid[] = "YOUR WIFI SSID HERE";
char pass[] = "YOUR WIFI PASSWORD HERE";

//variable for the on/off status of the computer
int powerState = 0;

//constants for device pins
const int powerLEDInPin = D6;
const int powerLEDOutPin = D2;
const int powerButtonPin = D7;
const int resetButtonPin = D8;

void setup()
{
  Serial.begin(115200); //for debugging
  pinMode(powerLEDInPin, INPUT_PULLUP); //!!pullup needs testing
  pinMode(powerLEDOutPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  powerState = digitalRead(powerLEDInPin);

  //power led passthrough to front panel
  if (powerState == HIGH)
  {
    digitalWrite(powerLEDOutPin, HIGH);
  }
  else
  {
    digitalWrite(powerLEDOutPin, LOW);
  }
  
  Blynk.run();
}

//reset button
BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();

  //if computer is not on, reset command wont be sent
  if (pinValue == HIGH)
  {
    powerState = digitalRead(powerLEDInPin);

    if (powerState != HIGH)
    {
      digitalWrite(resetButtonPin, LOW);
      Serial.println("Computer is not on.");
    }
    else
    {
      digitalWrite(resetButtonPin, HIGH);
      Serial.println("Resetting...");
    }
  }
  else
  {
    digitalWrite(resetButtonPin, LOW);
  }
}

//power button
BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();

  //if computer is already on, power up command wont be sent
  if (pinValue == HIGH)
  {
    powerState = digitalRead(powerLEDInPin);

    if (powerState != HIGH)
    {
      digitalWrite(powerButtonPin, HIGH);
      Serial.println("Starting...");
    }
    else
    {
      digitalWrite(powerButtonPin, LOW);
      Serial.println("Computer is already on.");
    }
  }
  else
  {
    digitalWrite(powerButtonPin, LOW);
  }
}

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YOUR BLYNK AUTH CODE HERE";
char ssid[] = "YOUR WIFI SSID HERE";
char pass[] = "YOUR WIFI PASSWORD HERE";

int powerState = 0;

int powerLEDInPin = D2;
int powerLEDOutPin = D6;
int powerButtonPin = D8;
int resetButtonPin = D7;

void setup()
{
  Serial.begin(115200);
  pinMode(powerLEDInPin, INPUT_PULLUP);
  pinMode(powerLEDOutPin, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  powerState = digitalRead(powerLEDInPin);
  
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

BLYNK_WRITE(V2)
{
  int pinValue = param.asInt();

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
      Serial.println("Resetting...")
    }
  }
  else
  {
    digitalWrite(resetButtonPin, LOW);
  }
}

BLYNK_WRITE(V3)
{
  int pinValue = param.asInt();

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

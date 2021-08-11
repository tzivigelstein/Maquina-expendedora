#include "Drink.cpp"
#include "Display.h"

//Custom machine variables
const int smallCupTime = 15000;
int cupTime = smallCupTime;

//Motors
const int motorWatter = 13;
const int motorCoffe = 12;
const int motorMilk = 11;

//Temperature
const int temperatureLimit = 90;

//Buttons
const int buttonAPin = 10;
const int buttonBPin = 9;
const int buttonCPin = 8;

Button buttonA(buttonAPin);
Button buttonB(buttonBPin);
Button buttonC(buttonCPin);

Display display;

void setup()
{
  Serial.begin(9600);
  display.init();

  for (int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  if (buttonA.isPressed())
  {
    //Black coffee

    digitalWrite(motorWatter, HIGH);
    delay(1000);
    digitalWrite(motorCoffe, HIGH);
    delay(4000);
    digitalWrite(motorCoffe, LOW);
    delay(10000);
    digitalWrite(motorWatter, LOW);
  }

  if (buttonB.isPressed())
  {
    //Latte

    digitalWrite(motorWatter, HIGH);
    delay(1000);
    digitalWrite(motorCoffe, HIGH);
    delay(4000);
    digitalWrite(motorCoffe, LOW);
    digitalWrite(motorMilk, HIGH);
    delay(8000);
    digitalWrite(motorMilk, LOW);
    delay(2000);
    digitalWrite(motorWatter, LOW);
  }

  if (buttonC.isPressed())
  {
    //White coffee

    digitalWrite(motorWatter, HIGH);
    delay(1000);
    digitalWrite(motorCoffe, HIGH);
    delay(4000);
    digitalWrite(motorCoffe, LOW);
    digitalWrite(motorMilk, HIGH);
    delay(4000);
    digitalWrite(motorMilk, LOW);
    delay(9500);
    digitalWrite(motorWatter, LOW);
  }
}

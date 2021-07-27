#include "Button.cpp"
#include "Drink.cpp"
#include "Component.cpp"
#include <LiquidCrystal.h>

//Display
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

//Motors
const int motorA = 13;
const int motorB = 12;
const int motorC = 11;

//Temperature
const int temperatureLimit = 90;

//Buttons
const int buttonAPin = 10;
const int buttonBPin = 9;
const int buttonCPin = 8;

Button buttonA(buttonAPin);
Button buttonB(buttonBPin);
Button buttonC(buttonCPin);

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Hello world");
}

void loop()
{
  //Get buttons actual state
  bool buttonAIsPressed = buttonA.isPressed();
  bool buttonBIsPressed = buttonB.isPressed();
  bool buttonCIsPressed = buttonC.isPressed();

  const int motorARef = digitalRead(motorA);
  const int motorBRef = digitalRead(motorB);
  const int motorCRef = digitalRead(motorC);

  if (buttonAIsPressed)
  {
    digitalWrite(motorA, HIGH);
    Drink drinkA(1000, 1000, temperatureLimit);
    drinkA.start();
  }
  else if (buttonBIsPressed)
  {
    digitalWrite(motorB, HIGH);
    Drink drinkB(1000, 1000, temperatureLimit);
    drinkB.start();
  }
  else if (buttonCIsPressed)
  {
    digitalWrite(motorC, HIGH);
    Drink drinkC(1000, 1000, temperatureLimit);
    drinkC.start();
  }
}

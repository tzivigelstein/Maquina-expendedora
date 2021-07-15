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
const int temperaturePin = A2;
Temperature temperature();

//Buttons
const int buttonAPin = 8;
const int buttonBPin = 9;
const int buttonCPin = 10;

Button buttonA(buttonAPin);
Button buttonB(buttonBPin);
Button buttonC(buttonCPin);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  //Get buttons actual state
  bool buttonAIsPressed = buttonA.isPressed();
  bool buttonBIsPressed = buttonB.isPressed();
  bool buttonCIsPressed = buttonC.isPressed();

  int actualTemperature = temperature.getTemperature();

  const int motorARef = digitalRead(motorA);
  const int motorBRef = digitalRead(motorB);
  const int motorCRef = digitalRead(motorC);

  if (buttonAIsPressed)
  {
    Drink drinkA();
    drinkA.start();
  }
  else if (buttonBIsPressed)
  {
    Drink drinkB();
    drinkB.start();
  }
  else if (buttonCIsPressed)
  {
    Drink drinkC();
    drinkC.start();
  }
}

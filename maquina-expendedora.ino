#include "Button.cpp"
#include "Drink.cpp"
#include "Display.h"

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

Display display;

void setup()
{
  Serial.begin(9600);
  display.init();
}

void loop()
{
  if (buttonA.isPressed())
  {
    //Black coffee
    static const int coffeeActive = 4000;
    static const int milkActive = 4000;
    static const int waterActive = 15000;

    Drink blackCoffee(temperatureLimit, coffeeActive, milkActive, waterActive);
    blackCoffee.start();
  }

  if (buttonB.isPressed())
  {
    //Latte
    static const int coffeeActive = 4000;
    static const int milkActive = 4000;
    static const int waterActive = 15000;

    Drink latte(temperatureLimit, coffeeActive, milkActive, waterActive);
    latte.start();
  }

  if (buttonC.isPressed())
  {
    //White coffee
    //static const int coffeeActive = 4000;
    //static const int milkActive = 4000;
    //static const int waterActive = 6000;

    static const int coffeeActive = 1000;
    static const int milkActive = 1000;
    static const int waterActive = 1000;

    Drink whiteCoffee(temperatureLimit, coffeeActive, milkActive, waterActive);
    whiteCoffee.start();
  }
}

#include "Drink.cpp"
#include "Display.h"

//Custom machine variables
const int smallCupTime = 15000;
int cupTime = smallCupTime;

//Motors
const int motorWater = 13;
const int motorCoffe = 12;
const int motorMilk = 11;
const int motorChocolate = 10;

//Temperature
const int temperatureLimit = 90;

//Buttons
const int buttonBlackCoffeePin = A2;
const int buttonLongBlackCoffeePin = A1;
const int buttonWhiteCoffeePin = 10;
const int buttonLattePin = 9;
const int buttonCappuccinoPin = 8;

Button buttonBlackCoffee(buttonBlackCoffeePin);
Button buttonLongBlackCoffee(buttonLongBlackCoffeePin);
Button buttonWhiteCoffee(buttonWhiteCoffee);
Button buttonLatte(buttonLattePin);
Button buttonCappuccino(buttonCappuccinoPin);

Display display;

void setup()
{
  Serial.begin(9600);
  display.init();

  for (int i = 0; i < 14; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop()
{
  if (buttonBlackCoffee.isPressed())
  {
    blackCoffee();
  }

  if (buttonLongBlackCoffee.isPressed())
  {
    longBlackCoffee();
  }

  if (buttonLatte.isPressed())
  {
    latte();
  }

  if (buttonWhiteCoffee.isPressed())
  {
    whiteCoffee();
  }

  if(buttonCappuccino.isPressed()){
    cappuccino();
  }
}

void blackCoffee()
{
  digitalWrite(motorWater, HIGH);
  delay(1000);
  digitalWrite(motorCoffe, HIGH);
  delay(3000);
  digitalWrite(motorCoffe, LOW);
  delay(10000);
  digitalWrite(motorWater, LOW);
}

void longBlackCoffee()
{
  digitalWrite(motorWater, HIGH);
  delay(1000);
  digitalWrite(motorCoffe, HIGH);
  delay(4000);
  digitalWrite(motorCoffe, LOW);
  delay(10000);
  digitalWrite(motorWater, LOW);
}

void latte()
{
  digitalWrite(motorWater, HIGH);
  delay(1000);
  digitalWrite(motorCoffe, HIGH);
  delay(4000);
  digitalWrite(motorCoffe, LOW);
  digitalWrite(motorMilk, HIGH);
  delay(8000);
  digitalWrite(motorMilk, LOW);
  delay(2000);
  digitalWrite(motorWater, LOW);
}

void whiteCoffee()
{
  digitalWrite(motorWater, HIGH);
  delay(1000);
  digitalWrite(motorCoffe, HIGH);
  delay(4000);
  digitalWrite(motorCoffe, LOW);
  digitalWrite(motorMilk, HIGH);
  delay(4000);
  digitalWrite(motorMilk, LOW);
  delay(9500);
  digitalWrite(motorWater, LOW);
}

void cappuccino (){
  digitalWrite(motorWater, HIGH);
  delay(1000);
  digitalWrite(motorCoffe, HIGH);
  delay(4000);
  digitalWrite(motorCoffe, LOW);
  digitalWrite(motorMilk, HIGH);
  delay(2000);
  digitalWrite(motorChocolate, HIGH);
  delay(6000);
  digitalWrite(motorMilk, LOW);
  digitalWrite(motorChocolate, LOW);
  delay(2000);
  digitalWrite(motorWater, LOW);
}

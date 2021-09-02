#include "Display.h"

//Motors
const int motorWater = 13;
const int motorCoffe = 12;
const int motorMilk = 11;
const int motorChocolate = 10;

Display newDisplay;

void initDrink () {
  newDisplay.print("Temperatura OK");
  delay(3000);
  newDisplay.print("Empezando", "proceso");
  delay(2000);
  newDisplay.print("Llenando...");
}

void blackCoffee(int cupTime)
{
  initDrink();
  digitalWrite(motorWater, HIGH);
  delay(round(0.0666 * cupTime));
  digitalWrite(motorCoffe, HIGH);
  delay(round(0.2 * cupTime));
  digitalWrite(motorCoffe, LOW);
  delay(round(0.666 * cupTime));
  digitalWrite(motorWater, LOW);
  newDisplay.print("Seleccione un", "cafe");
}

void longBlackCoffee(int cupTime)
{
  initDrink();
  digitalWrite(motorWater, HIGH);
  delay(round(0.0666 * cupTime));
  digitalWrite(motorCoffe, HIGH);
  delay(round(0.26 * cupTime));
  digitalWrite(motorCoffe, LOW);
  delay(round(0.6666 * cupTime));
  digitalWrite(motorWater, LOW);
  newDisplay.print("Seleccione un", "cafe");
}

void latte(int cupTime)
{
  initDrink();
  digitalWrite(motorWater, HIGH);
  delay(round(0.0666 * cupTime));
  digitalWrite(motorCoffe, HIGH);
  delay(round(0.2666 * cupTime));
  digitalWrite(motorCoffe, LOW);
  digitalWrite(motorMilk, HIGH);
  delay(round(0.5333 * cupTime));
  digitalWrite(motorMilk, LOW);
  delay(round(0.1333 * cupTime));
  digitalWrite(motorWater, LOW);
  newDisplay.print("Seleccione un", "cafe");
}

void whiteCoffee(int cupTime)
{
  initDrink();
  digitalWrite(motorWater, HIGH);
  delay(round(0.0666 * cupTime));
  digitalWrite(motorCoffe, HIGH);
  delay(round(0.2666 * cupTime));
  digitalWrite(motorCoffe, LOW);
  digitalWrite(motorMilk, HIGH);
  delay(round(0.2666 * cupTime));
  digitalWrite(motorMilk, LOW);
  delay(round(0.6333 * cupTime));
  digitalWrite(motorWater, LOW);
  newDisplay.print("Seleccione un", "cafe");
}

void cappuccino(int cupTime)
{
  initDrink();
  digitalWrite(motorWater, HIGH);
  delay(round(0.0666 * cupTime));
  digitalWrite(motorCoffe, HIGH);
  delay(round(0.2666 * cupTime));
  digitalWrite(motorCoffe, LOW);
  digitalWrite(motorMilk, HIGH);
  delay(round(0.1333 * cupTime));
  digitalWrite(motorChocolate, HIGH);
  delay(round(0.4 * cupTime));
  digitalWrite(motorMilk, LOW);
  digitalWrite(motorChocolate, LOW);
  delay(round(0.1333 * cupTime));
  digitalWrite(motorWater, LOW);
  newDisplay.print("Seleccione un", "cafe");
}

#include "Temperature.h"
#include "Display.h"
#include "Coffees.h"

//Temperature
int temperatureLimit = 90;
int actualTemperature;

//Buttons
const int blackCoffeePin = A5;
const int longBlackCoffeePin = A4;
const int lattePin = A3;
const int whiteCoffeePin = A2;
const int cappuccinoPin = A1;

Display display;
Temperature temperature;

int lastReading = 0;
unsigned long onTime = 0;
int hold = 0;
int holdTime = 1000;
int bounceTime = 50;
int program = 0;

bool isLightOn = true;

const int maxMenus = 3;

const String menus[maxMenus] = {"Temperatura", "Luz de alerta", "Medida taza"};
int menuPosition = 0;

const int maxSizes = 3;
const String sizes[maxSizes] = {"Chica 250ml", "Mediana 300ml", "Grande 500ml"};
const int sizesInt[maxSizes] = {15000, 22000, 30000};

int cupTime = sizesInt[0];

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
  actualTemperature = temperature.getTemperature();
  int temperatureIsOk = temperature.isTemperatureArround(temperatureLimit);

  if (temperatureIsOk && isLightOn)
  {
    digitalWrite(9, HIGH);
  }
  else
  {
    digitalWrite(9, LOW);
  }

  int rawReading = analogRead(blackCoffeePin);
  int reading = map(rawReading, 0, 1020, 0, 1);

  if (reading == HIGH && lastReading == LOW)
  {
    onTime = millis();
  }

  if (reading == HIGH && lastReading == HIGH)
  {
    if ((millis() - onTime) > holdTime)
    {
      hold = 1;
    }
  }

  if (reading == LOW && lastReading == HIGH)
  {
    if (((millis() - onTime) > bounceTime && hold != 1))
    {
      // Black Coffee
      blackCoffee(cupTime);
    }
    if (hold == 1 && program != 1)
    {
      programMode();
      hold = 0;
    }
    else if (hold == 1 && program == 1)
    {
      display.init();
      for (int w = 8; w < 14; w++)
      {
        digitalWrite(w, HIGH);
        delay(100);
        digitalWrite(w, LOW);
      }
      program = 0;
    }
  }

  lastReading = reading;

  //Long black coffee

  if (isPressed(longBlackCoffeePin) && temperatureIsOk && program != 1)
  {
    longBlackCoffee(cupTime);
  }

  if (isPressed(longBlackCoffeePin) && program == 1)
  {
    if (menuPosition == 0)
      return;

    String nextOption = "----";
    if (menuPosition > 0)
    {
      menuPosition--;
      int nextMenuPosition = menuPosition + 1;
      nextOption = menus[nextMenuPosition];
    }

    String parsedOption = "> " + menus[menuPosition];
    display.print(parsedOption, nextOption);
  }

  //Latte

  if (isPressed(lattePin) && temperatureIsOk && program != 1)
  {
    latte(cupTime);
  }

  if (isPressed(lattePin) && program == 1)
  {
    String nextOption = "----";
    const int maxMenusBound = maxMenus - 1;
    if (menuPosition < maxMenusBound)
    {
      menuPosition++;

      int nextMenuPosition;
      if (menuPosition < maxMenusBound)
      {
        nextMenuPosition = menuPosition + 1;
        nextOption = menus[nextMenuPosition];
      }
    }
    String parsedOption = "> " + menus[menuPosition];

    display.print(parsedOption, nextOption);
  }

  //White Coffee

  if (isPressed(whiteCoffeePin) && temperatureIsOk && program != 1)
  {
    whiteCoffee(cupTime);
  }

  if (isPressed(whiteCoffeePin) && program == 1)
  {
    if (menuPosition == 0)
    {
      const String limitBoilerplate = "Limite ";
      const String limitBoilerPlate2 = " \337C";
      const String limitTemperatureText = limitBoilerplate + temperatureLimit + limitBoilerPlate2;
      display.print(limitTemperatureText);
      while (!isPressed(cappuccinoPin))
      {
        if (isPressed(longBlackCoffeePin) && temperatureLimit < 90)
        {
          temperatureLimit++;
          const String limitTemperatureText = limitBoilerplate + temperatureLimit + limitBoilerPlate2;
          display.print(limitTemperatureText);
        }
        else if (isPressed(lattePin) && temperatureLimit > 82)
        {
          temperatureLimit--;
          const String limitTemperatureText = limitBoilerplate + temperatureLimit + limitBoilerPlate2;
          display.print(limitTemperatureText);
        }
      }

      programMode();
    }

    if (menuPosition == 1)
    {
      String lightOnText;
      if (isLightOn)
      {
        lightOnText = "Luz activa";
      }
      else
      {
        lightOnText = "Luz inactiva";
      }
      display.print(lightOnText);
      while (!isPressed(cappuccinoPin))
      {
        if (isPressed(longBlackCoffeePin))
        {
          isLightOn = true;
          lightOnText = "Luz activa";
          display.print(lightOnText);
        }
        else if (isPressed(lattePin))
        {
          isLightOn = false;
          lightOnText = "Luz inactiva";
          display.print(lightOnText);
        }
      }
      programMode();
    }

    if (menuPosition == 2)
    {
      int sizePosition = 0;

      switch (cupTime)
      {
        case 15000:
          display.print(sizes[0]);
          break;

        case 22000:
          display.print(sizes[1]);
          sizePosition = 1;
          break;

        case 30000:
          display.print(sizes[2]);
          sizePosition = 2;
          break;

        default:
          break;
      }

      while (!isPressed(cappuccinoPin))
      {
        if (isPressed(longBlackCoffeePin) && sizePosition > 0)
        {
          sizePosition--;
          display.print(sizes[sizePosition]);
          cupTime = sizesInt[sizePosition];
        }
        else if (isPressed(lattePin) && sizePosition < maxSizes - 1)
        {
          sizePosition++;
          cupTime = sizesInt[sizePosition];
          display.print(sizes[sizePosition]);
        }
      }

      programMode();
    }
  }

  //Cappuccino

  if (isPressed(cappuccinoPin) && temperatureIsOk && program != 1)
  {
    cappuccino(cupTime);
  }

  if (isPressed(cappuccinoPin) && program == 1)
  {
    // Do something when back button (cappuccino button) is pressed
    // I didn't use it
  }
}

bool isPressed(int pin)
{
  pinMode(pin, INPUT);
  int debounceDelay = 160;
  int lastButtonState = 0;
  int buttonState = 0;
  int state = false;
  buttonState = digitalRead(pin);

  if (buttonState != lastButtonState)
  {
    if (buttonState == HIGH)
    {
      state = true;
    }
    else
    {
      state = false;
    }
    delay(debounceDelay);
  }

  lastButtonState = buttonState;

  return state;
}

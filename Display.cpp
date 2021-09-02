#include "Display.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

Display::Display()
{
  init();
}

void Display::init()
{
  lcd.begin(16, 2);
  print("Seleccione un", "cafe");
}

void Display::print(String firstMessage = "", String secondMessage = "")
{
  clear();

  if (!(firstMessage == ""))
  {
    const int firstMessageLenght = firstMessage.length();
    const int cursorCenter = (16 - firstMessageLenght) / 2;

    lcd.setCursor(cursorCenter, 0);
    lcd.print(firstMessage);
  }

  if (!(secondMessage == ""))
  {
    const int secondMessageLenght = secondMessage.length();
    const int cursorCenter = (16 - secondMessageLenght) / 2;

    lcd.setCursor(cursorCenter, 1);
    lcd.print(secondMessage);
  }
}

void Display::clear()
{
  lcd.clear();
}

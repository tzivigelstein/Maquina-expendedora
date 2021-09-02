void programMode()
{
  for (int w = 8; w < 14; w++)
  {
    digitalWrite(w, HIGH);
    delay(100);
    digitalWrite(w, LOW);
  }

  String nextOption = menus[1];
  String option = "> " + menus[0];
  menuPosition = 0;

  display.print(option, nextOption);

  program = 1;
}

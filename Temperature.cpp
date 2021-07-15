#include <Arduino.h>

class Temperature
{
private:
    int temperature;

public:
    Temperature()
    {
    }

    int getTemperature()
    {
        return analogRead(temperaturePin);
    }
};
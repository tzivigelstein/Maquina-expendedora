#include <Arduino.h>
#include "Temperature.cpp"
#include "Motor.cpp"
#include "Component.cpp"

class Drink
{
private:
    int time;
    int delay;

public:
    Drink(int delay, int time)
    {
        this->time = time;
        this->delay = delay;
        Temperature temperature();
    }

    void start()
    {
        if (temperature.isTemperatureArround(temperatureLimit))
        {
            Serial.print("Temperature OK")
        }
    }

    void stop()
    {
    }
};
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
        this->variationRange = 0.1;
        Temperature temperature(variationRange);
    }

    void start()
    {
        Serial.prinln("Checking temperature");
        if (temperature.isTemperatureArround(temperatureLimit))
        {
            Serial.println("Temperature OK");
            Serial.println("Starting process");
            
        }
    }

    void stop()
    {
    }
};
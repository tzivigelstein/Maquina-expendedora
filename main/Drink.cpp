#include <Arduino.h>
#include "Temperature.cpp"
#include "Motor.cpp"

class Drink
{
private:
    int time;
    int delay;
    int variationRange;
    int temperatureLimit;
    Temperature temperature;

public:
    Drink(int delay, int time, int temperatureLimit) : temperature(variationRange)
    {
        this->time = time;
        this->delay = delay;
        this->variationRange = 0.1;
        this->temperatureLimit = temperatureLimit;
    }

    void start()
    {
        Serial.println("Checking temperature");
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

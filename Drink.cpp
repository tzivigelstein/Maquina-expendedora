#include <Arduino.h>
#include "Component.cpp"
#include "Motor.cpp"

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
    }

    void start()
    {
        if(actualTemperature < temperatureLimit)
    }

    void stop()
    {
        
    }
};
#ifndef temperature_h
#define temperature_h
#include <Arduino.h>

class Temperature
{
private:
    const int temperaturePin = A0;

public:
    Temperature();
    bool isTemperatureArround(int);
    int getTemperature();
};

#endif

#include "Temperature.h"

Temperature::Temperature()
{
}

int Temperature::getTemperature()
{
    int temperatureMeasure = analogRead(temperaturePin);
    int parsedTemperature = map(temperatureMeasure, 0, 1024, 15, 110);
    return parsedTemperature;
}

bool Temperature::isTemperatureArround(int temperatureLimit)
{
    int actualTemperature = getTemperature();
    return actualTemperature == temperatureLimit;
}

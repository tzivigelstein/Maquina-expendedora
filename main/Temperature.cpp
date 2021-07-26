#include <Arduino.h>

class Temperature
{
private:
    int variationRange;
    const int temperaturePin = A2;

public:
    Temperature(int variationRange)
    {
        this->variationRange = variationRange;
    }

    int getTemperature()
    {
        return analogRead(temperaturePin);
    }

    bool isTemperatureArround(int temperatureLimit)
    {
        int actualTemperature = getTemperature();
        int temperatureVariation = temperatureLimit * variationRange;
        int lowestAcceptableTemperature = temperatureLimit - temperatureVariation;
        int highestAcceptableTemperature = temperatureLimit + temperatureVariation;
        return actualTemperature > lowestAcceptableTemperature && actualTemperature < highestAcceptableTemperature;
    }
};

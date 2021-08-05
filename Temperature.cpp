#include <Arduino.h>

class Temperature
{
private:
    float variationRange;
    const int temperaturePin = A2;

public:
    Temperature(float variationRange)
    {
        this->variationRange = variationRange;
    }

    int getTemperature()
    {
        //return analogRead(temperaturePin); Uncomment when temperature sensor is plugged.
        //Maybe need to map values.
        return 90;
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

#include <Arduino.h>

class Temperature
{
private:
  float variationRange;
  const int temperaturePin = A0;

public:
  Temperature(float variationRange)
  {
    this->variationRange = variationRange;
  }

  int getTemperature()
  {
    //return analogRead(temperaturePin); Uncomment when temperature sensor is plugged.
    //Maybe need to map values.
    int temperatureMeasure = analogRead(temperaturePin);
    int parsedTemperature = map(temperatureMeasure, 0, 1024, 15, 110);
    return parsedTemperature;
  }

  bool isTemperatureArround(int temperatureLimit)
  {
    int actualTemperature = getTemperature();
    return actualTemperature == temperatureLimit;
  }
};

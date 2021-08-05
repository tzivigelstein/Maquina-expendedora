#include <Arduino.h>
#include "Temperature.cpp"
#include "Motor.cpp"
#include "Display.h"

class Drink
{
private:
    int coffeeMotorPin = 13;
    int milkMotorPin = 12;
    int waterMotorPin = 11;
    const float variationRange = 0.1f;
    int temperatureLimit;
    int coffeeDelay;
    int coffeeActive;
    int milkDelay;
    int milkActive;
    int waterDelay;
    int waterActive;
    Temperature temperature;
    Display display;
    Motor coffeeMotor;
    Motor milkMotor;
    Motor waterMotor;
    static constexpr int defaultArray[2] = {0, 0};

public:
    Drink(int temperatureLimit, int coffeeActive, int milkActive, int waterActive) : temperature(variationRange),
                                                                                     display(),
                                                                                     coffeeMotor(coffeeMotorPin),
                                                                                     milkMotor(milkMotorPin),
                                                                                     waterMotor(waterMotorPin)
    {
        this->temperatureLimit = temperatureLimit;
        this->coffeeActive = coffeeActive;
        this->milkActive = milkActive;
        this->waterActive = waterActive;
    }

    void start(String tag = "Café")
    {
        display.print("Checking", "temperature");
        if (temperature.isTemperatureArround(temperatureLimit))
        {
            const String actualTemperature = String(temperature.getTemperature());
            const String temperatureDisplay = actualTemperature + " C";
            display.print("Temperatura OK", temperatureDisplay);
            delay(3000);
            display.print("Empezando", "proceso");
            delay(2000);
            display.print("Llenando...");
            coffeeMotor.start(coffeeActive);
            milkMotor.start(milkActive);
            waterMotor.start(waterActive);
            stop();
        }
    }

    void stop()
    {
        display.print("Listo");
        delay(5000);
        display.init();
    }
};

#include <Arduino.h>

class Motor
{
private:
    int motor;

public:
    Motor(int motor)
    {
        this->motor = motor;
        pinMode(motor, OUTPUT);
    }

    void start(int activeTime)
    {
        digitalWrite(motor, HIGH);
        delay(activeTime);
        Serial.println(activeTime);
        stop();
    }

    void stop()
    {
        digitalWrite(motor, LOW);
    }
};

#include <Arduino.h>

class Motor
{
private:
    int motor;

public:
    Motor(int motor)
    {
        this->motor = motor;
    }

    void start()
    {
        digitalWrite(motor, HIGH);
    }

    void stop()
    {
        digitalWrite(motor, LOW);
    }
};

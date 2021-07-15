#include <Arduino.h>

class Motor
{
private:
public:
    Motor()
    {
    }

    void start()
    {
        digitalWrite(motorA, HIGH);
    }

    void stop()
    {
        digitalWrite(motorA, LOW);
    }
}
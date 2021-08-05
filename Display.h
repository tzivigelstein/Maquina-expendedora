#ifndef DISPLAY_H
#define DISPLAY_H
#include <Arduino.h>

class Display
{
private:
public:
    Display();

    void init();
    void print(String firstMessage = "", String secondMessage = "");
    void clear();
};

#endif

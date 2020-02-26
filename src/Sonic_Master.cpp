#if ARDUINO >=100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

#include "Sonic.h"

Sonic::Sonic(uint8_t pinTrig, uint8_t pinEcho, unsigned long timeOut) {
    trig = pinTrig;
    echo = pinEcho;
    ping = trig == echo ? true : false;
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    timeout = timeOut;
}

unsigned int Sonic::count() {
    if (ping)
        pinMode(trig, OUTPUT);

    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    if (ping)
        pinMode(trig, INPUT);

    prevMicros = micros();
    while(!digitalRead(echo) && (micros() - prevMicros) <= timeout);
    prevMicros = micros();
    while(digitalRead(echo) && (micros() - prevMicros) <= timeout);

    return micros() - prevMicros;
}

unsigned int Sonic::read(uint8_t und) {
    return count() / und / 2;
}

unsigned int Sonic::distanceRead(uint8_t und) {
    return read(und);
}
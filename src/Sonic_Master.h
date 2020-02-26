#ifndef Sonic_h
#define Sonic_h

#define MM 2800
#define IN 71

class Sonic {
    public:
        Sonic(uint8_t pinSig) : Sonic(pinSig, pinSig) {};
        Sonic(uint8_t pinTrig, uint8_t pinEcho, unsigned long timeOut = 22000UL);
        unsigned int read(uint8_t und = MM);
        unsigned int distanceRead(uint8_t und = MM);
        void setTimeout(unsigned long timeOut) {timeout = timeOut;}
    
    private:
        uint8_t trig;
        uint8_t echo;
        bool pings = false;
        unsigned long prevMicros;
        unsigned long timeout;
        unsigned int count();
};

#endif

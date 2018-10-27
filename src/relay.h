#include <Arduino.h>

class Relay {
  public:
    Relay();

    void setup(int t_pin);
    
    void turnOn();
    void turnOff();

    uint8_t getState();

  private:
    int m_pin = 0;

};
#include "relay.h"

Relay::Relay() {
  
}

void Relay::setup(int t_pin) {
  this->m_pin = t_pin;

  pinMode(t_pin, OUTPUT);
  digitalWrite(t_pin, HIGH);
}

void Relay::turnOn() {
  digitalWrite(this->m_pin, LOW);
}

void Relay::turnOff() {
  digitalWrite(this->m_pin, HIGH);
}

uint8_t Relay::getState() {
  return digitalRead(this->m_pin);
}
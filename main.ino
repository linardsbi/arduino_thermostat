#include "DHTesp.h"
#include "src/Defines.h"

#include "src/util/Time.h"
#include "src/WIFI.h"
#include "src/relay.h"

DHTesp dht;
Relay relay;

unsigned wakeupHigher = 0;

void setup()
{
  Serial.begin(115200);

  if (WIFI::connect()) {
    Serial.println("connected");
  }

  dht.setup(PIN_DHT11, DHTesp::DHT11);
  relay.setup(PIN_RELAY);
}

bool timeIsWithinNeeded(unsigned &time) {
  String currentYMD = Time::date(time, "%Y-%m-%d") + " " + WAKEUP_TIME;
 
  wakeupHigher = Time::strtotime(currentYMD.c_str(), "%Y-%m-%d %H:%M:%S");

   if (time > wakeupHigher) {
    wakeupHigher += ONE_DAY;
  }

  return time >= wakeupHigher - RELAY_RUN_TIME && time <= wakeupHigher;
}

void handleRelayState() {
  uint8_t humidity = dht.getHumidity();
  uint8_t temperature = dht.getTemperature();

  if (temperature > 20) {
    relay.turnOff();
  } else if (temperature == temperature) { // is not NaN
    relay.turnOn();
  }
}


void delayUntilNeeded(unsigned &time) {
  unsigned delay = (wakeupHigher - RELAY_RUN_TIME) - time;

  Serial.print("Sleeping for: ");
  Serial.print(delay);
  Serial.println(" seconds");

  if (delay > 3600) {
    ESP.deepSleep(MICROSECONDS_IN_ONE_HOUR);
  } else {
    long unsigned temp = Time::secondsToMicroseconds(delay);

    ESP.deepSleep(temp);
  }
}

void loop()
{
  //  delay(dht.getMinimumSamplingPeriod());

  unsigned currentTime = Time::time();

  if (timeIsWithinNeeded(currentTime)) {
    handleRelayState();
    Serial.println("was within needed");
    delay(5000);
  } else {
    relay.turnOff();
    delayUntilNeeded(currentTime);
  }
}

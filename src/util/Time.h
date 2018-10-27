#include <Arduino.h>
#include "../Defines.h"
#include "Json.h"
#include "Http.h"


class Time {
  public:
    static int strtotime(const char* t_timeString, const char* t_format);
    static String date(time_t t_epochTime, const char* t_format);
    static int time();
    static unsigned long secondsToMicroseconds(unsigned &t_seconds) {
      return (long)(t_seconds * 1000000);
    }

};
#include <Arduino.h>
#include "../Defines.h"
#include "Json.h"
#include "Http.h"


class Time {
  public:
    static int strtotime(const char* t_timeString, const char* t_format);
    static String date(time_t t_epochTime, const char* t_format);
    static int time();

};
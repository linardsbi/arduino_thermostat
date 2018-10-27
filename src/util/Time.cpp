#include "Time.h"
#include <ctime>
#include <time.h>
int Time::strtotime(const char* t_timeString, const char* t_format = "%Y-%m-%d %H:%M:%S") {

  // if (t_relative < 0) {
  //   t_relative = this::time();

  //   if (t_relative == -1) {
  //     return t_relative;
  //   }
  // }

  std::tm tmTime;
  memset(&tmTime, 0, sizeof(tmTime));
  strptime(t_timeString, t_format, &tmTime);

  return (int)mktime(&tmTime);
}

String Time::date(time_t t_epochTime, const char* t_format = "%Y-%m-%d %H:%M:%S") {
  char timestamp[64] = {0};
  strftime(timestamp, sizeof(timestamp), t_format, gmtime(&t_epochTime));
  return timestamp;
}

int Time::time() {
  String response = Http::sendSimpleGETRequest(TIME_API_LINK);
  
  JsonObject& root = Json::parse(response.c_str());

  // Test if parsing succeeds.
  if (!root.success()) {
    return -1;
  }

  return root["timestamp"];
}

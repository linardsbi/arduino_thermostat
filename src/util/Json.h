#include <ArduinoJson.h>

#define SIZE_TIMESTAMP JSON_OBJECT_SIZE(3) + 50

class Json {
  public:
    static JsonObject& parse(const char* t_payload);

};
#include "Json.h"

JsonObject& Json::parse(const char* t_payload) {
  const size_t bufferSize = SIZE_TIMESTAMP;

  DynamicJsonBuffer jsonBuffer(bufferSize);

  return jsonBuffer.parseObject(t_payload);
}
#include <ESP8266HTTPClient.h>
#include "Http.h"

Http::Http() {}

String Http::sendSimpleGETRequest(const char* t_host) {
  HTTPClient http;    //Declare object of class HTTPClient
  http.begin(t_host);     //Specify request destination

  uint16_t httpCode = http.GET(); //Send the request
  String response = http.getString();

  http.end();      //Close connection
  return response; //Get the response payload
}
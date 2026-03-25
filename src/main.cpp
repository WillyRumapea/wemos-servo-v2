#include <Arduino.h>
#include <Servo.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#define BTN_INC D3
#define BTN_DEC D4

Servo servoku;
ESP8266WebServer server(80);

int posDeg = 0;

const char* ssid = "BIZNET 5G";
const char* password = "$2b$12$PoL2wIbyQf3O51/NNndnRu3wWHs2xOJ8ZxXMDep6WF5e8qiHHVmfW";

void handleGetData(){
  String data = String(posDeg);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", data);
}

void handlePostData(){
  server.sendHeader("Access-Control-Allow-Origin", "*");
  if(server.hasArg("plain")){
    String body = server.arg("plain");
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, body);

    if(!error){
      int newPostDeg = doc["sudut"];
      
      if(newPostDeg >= 0 && newPostDeg <= 180){
        posDeg = newPostDeg;
        servoku.write(posDeg);
        Serial.print("sudut dari post: ");
        Serial.println(posDeg);
        server.send(200, "application/json", "{\"status\": \"ok\"}");
      }
    }else{
      server.send(400, "application/json", "{\"status\": \"gagal\"}");
    }
  }
}

void handleRoot(){
  server.send(200, "text/html", "<h1>hello from ESP8266</h1>");
}

void setup() {
  Serial.begin(115200);
  servoku.attach(D2, 500, 2400);
  servoku.write(0);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    delay(100);
    Serial.print("..");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/getData", handleGetData);
  server.on("/postData", HTTP_OPTIONS, []() {
    server.sendHeader("Access-Control-Allow-Origin", "*");
    server.sendHeader("Access-Control-Allow-Methods", "POST, GET, OPTIONS");
    server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
    server.send(204);
  });
  server.on("/postData", HTTP_POST, handlePostData);
  server.begin();

  pinMode(BTN_INC, INPUT_PULLUP);
  pinMode(BTN_DEC, INPUT_PULLUP);
}

void loop() {
  server.handleClient();

  int incState = digitalRead(BTN_INC);
  int decState = digitalRead(BTN_DEC);

  if(incState == LOW && posDeg < 180){
    posDeg++;
    servoku.write(posDeg);
    delay(15);
    Serial.print("inc ditekan, posDeg: ");
    Serial.println(posDeg);
  }
  
  if(decState == LOW && posDeg > 0){
    posDeg--;
    servoku.write(posDeg);
    delay(15);
    Serial.print("dec ditekan, posDeg: ");
    Serial.println(posDeg);
  }
}

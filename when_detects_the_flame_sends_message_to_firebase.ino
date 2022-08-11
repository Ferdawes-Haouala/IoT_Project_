int digital_pin = D2;
int BuzzerPin = D8;
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseObject.h>

#define FIREBASE_HOST "new-project-ec552-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "QtmUBviLdWs0vxYLcJSJ7ULoCJSVyY8ODeUZwoP5"
#define WIFI_SSID "A12"
#define WIFI_PASSWORD "12716207"

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.print("Connected to");
  Serial.println(WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(2000);
  pinMode(digital_pin, INPUT);
  Serial.begin(9600); 
  pinMode(BuzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int digitalVal = digitalRead(digital_pin);
  if(digitalVal == 0){
    String MSG= "No Flame in House";
    Firebase.setString("/msg", MSG);
    Serial.println(digitalVal);
    delay(4000);
  }
  else{
    String MSG= "Flame in House";
    Firebase.setString("/msg", MSG);
    Serial.println(digitalVal);
    delay(4000);
  }

}

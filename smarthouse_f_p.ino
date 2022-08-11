int sensorpin = A0;
int sensorlight = 700;
int digital_pin = D2;
int BuzzerPin = D8;
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseObject.h>

#define FIREBASE_HOST "iot-project-9b220-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "ppIZvN2ifUgLdagXXl4ceAFsnywkPjaHbhNCz4zQ"
#define WIFI_SSID "FOYER 17"
#define WIFI_PASSWORD "Espoir2021"

void setup() {
  pinMode(sensorpin, INPUT);
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.print("Connectedto");
  Serial.println(WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  delay(2000);
  pinMode(digital_pin, INPUT);
  Serial.begin(9600); 
  pinMode(BuzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float Value = analogRead(sensorpin);
  Serial.println(Value);
  delay(1000);
  if (Value>sensorlight){
  Serial.println("it is dark, the light is on");
  String MSG= "it is dark, the light is on";
  Firebase.setString("/light", MSG);
}
else{
    Serial.println("it is not dark, the light is off");
    String MSG= "it is not dark, the light is off";
    Firebase.setString("/light", MSG);

}
int digitalVal = digitalRead(digital_pin);
  if(digitalVal == 0){
    String MSG= "No Flame in House";
    Firebase.setString("/msg", MSG);
    Serial.println(digitalVal);
    digitalWrite(BuzzerPin, LOW);
    delay(4000);
  }
  else{
    String MSG= "Flame in House";
    Firebase.setString("/msg", MSG);
    Serial.println(digitalVal);
    digitalWrite(BuzzerPin, HIGH);
    delay(4000);
}
}

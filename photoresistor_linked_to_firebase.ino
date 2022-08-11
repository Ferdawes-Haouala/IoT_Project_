int sensorpin = A0;
int sensorlight = 700;
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseObject.h>

#define FIREBASE_HOST "iot-project-9b220-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "ppIZvN2ifUgLdagXXl4ceAFsnywkPjaHbhNCz4zQ"
#define WIFI_SSID "FOYER 7"
#define WIFI_PASSWORD "Espoir2021"

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorpin, INPUT);
  Serial.begin(9600);
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
}

void loop() {
  // put your main code here, to run repeatedly:
  float Value = analogRead(sensorpin);
  Serial.println(Value);
  delay(1000);
  if (Value>sensorlight){
  Serial.println("it is dark, the light is on");
  String MSG= "it is dark, the light is on";
  Firebase.setString("/msg", MSG);
}
else{
    Serial.println("it is not dark, the light is off");
    String MSG= "it is not dark, the light is off";
    Firebase.setString("/msg", MSG);

}
}

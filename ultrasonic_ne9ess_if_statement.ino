int trigPin = D7;    // TRIG pin
int echoPin = D8;    // ECHO pin
float duration_us, distance_cm;

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseObject.h>

#define FIREBASE_HOST "new-project-ec552-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "QtmUBviLdWs0vxYLcJSJ7ULoCJSVyY8ODeUZwoP5"
#define WIFI_SSID "FOYER 17"
#define WIFI_PASSWORD "Espoir2021"

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration_us = pulseIn(echoPin, HIGH);
  distance_cm = 0.017 * duration_us;
  Serial.print("duration us: ");
  Serial.print(duration_us);
  Serial.println(" us");
 // Serial.print("distance: ");
 // Serial.print(distance_cm);
//  Serial.println(" cm");
  delay(500);
  // put your main code here, to run repeatedly:
  if(duration_us > 500){
  String msg= "no one is here";
  Firebase.setString("/msg", msg);
  Serial.println("MSG");
}
else{
  String msg= "Someone is here";
  Firebase.setString("/msg", msg);
  Serial.println("MSG");
}
}

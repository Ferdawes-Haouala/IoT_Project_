int buzzer = 8;
int smokeD0 = A0;
// Your threshold value
int sensorThres = 400;
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseObject.h>

#define FIREBASE_HOST "new-project-ec552-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "QtmUBviLdWs0vxYLcJSJ7ULoCJSVyY8ODeUZwoP5"
#define WIFI_SSID "FOYER 17"
#define WIFI_PASSWORD "Espoir2021"
void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeD0, INPUT);
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
  int analogSensor = analogRead(smokeD0);

  Serial.println("Pin D0: ");
  Serial.println(analogSensor);
 // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
  Serial.print(" | Smoke detected!");
  String msg= "Smoke detected!";
  Firebase.setString("/msg", msg);
  Serial.println("MSG");
  digitalWrite ( buzzer, HIGH);
  delay(4000);
  }
else
 { 
  String msg= "Smoke not detected!";
  Firebase.setString("/msg", msg);
  Serial.println("MSG");
  Serial.print(" | Smoke not detected!");
  digitalWrite ( buzzer, HIGH);
  delay(4000);
  }
 delay(1000);
}

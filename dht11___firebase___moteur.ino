#include <Servo.h>
#include <DHT.h>
#define DHTPIN 0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <FirebaseObject.h>

#define FIREBASE_HOST "new-project-ec552-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "QtmUBviLdWs0vxYLcJSJ7ULoCJSVyY8ODeUZwoP5"
#define WIFI_SSID "FOYER 7"
#define WIFI_PASSWORD "Espoir2021"
Servo servo;

void setup() {
  servo.attach(13); //D4

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
  Serial.begin(9600);
  dht.begin();
}

void loop() {
float h = dht.readHumidity();
float t = dht.readTemperature();
Serial.print(" Humidity :" );
Serial.print( h );
Serial.println( "%" );
Serial.print(" Temperature :" );

Serial.print( t );
Serial.println( " °C" );
delay(1000);

if(t > 20){
    String MSG= "It is hot, Fan is on";
    Firebase.setString("/msg", MSG);
    Serial.println(t);
    servo.detach();
    delay(2000);
    servo.attach(13);
    servo.write(360);
    delay(1000);
    servo.write(0);
    delay(2000);
  }
  else{
    String MSG= "it is not hot, Fan is off";
    Firebase.setString("/msg", MSG);
    Serial.println(t);

  }
}

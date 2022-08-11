int greenPin = 4; //D2
void setup() {
pinMode(greenPin, OUTPUT);
}
void loop() {
digitalWrite ( greenPin, LOW);
delay(2000);
digitalWrite ( greenPin, HIGH); // turn the green led on
delay(2000);
}

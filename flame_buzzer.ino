int digital_pin = A5;
//int BuzzerPin = D8;

void setup() {
pinMode(digital_pin, INPUT);
Serial.begin(9600); 
//pinMode(BuzzerPin, OUTPUT);
//Serial.begin(9600);
}

void loop() {

  int digitalVal = analogRead(digital_pin);
   Serial.println(digitalVal);

//  if(digitalVal == 0){
//    Serial.println(digitalVal);
//    digitalWrite ( BuzzerPin, HIGH);
//    delay(4000);
//  }
//  else{
//    Serial.println(digitalVal);
//    digitalWrite ( BuzzerPin, LOW);
//    delay(4000);
//  }
}

const int LeftmotorPin1 = 12; // Assign Digital pin 12 of Arduino to Left Motor Pin1
const int LeftmotorPin2 = 11; // Assign Digital pin 11 of Arduino to Left Motor Pin2
const int RightmotorPin3 = 10; // Assign Digital pin 10 of Arduino to Right Motor Pin3
const int RightmotorPin4 = 9; // Assign Digital pin 9 of Arduino to Right Motor Pin4

#define Rightsensor 2 // Assign Digital pin 2 of Arduino to Right Sensor
#define Leftsensor 3 // Assign Digital pin 3 of Arduino to Left Sensor
byte i;

void setup() {
  // set the sensor pins as an input:
  pinMode(Leftsensor,INPUT);
  pinMode(Rightsensor,INPUT);
  
  // set all the other pins you&#39;re using as outputs:
  pinMode(LeftmotorPin1, OUTPUT);
  pinMode(LeftmotorPin2, OUTPUT);
  pinMode(RightmotorPin3, OUTPUT);
  pinMode(RightmotorPin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(Leftsensor));
  Serial.println(digitalRead(Rightsensor));
  delay(5);
  
  // if both sensors are 0, Left motor will turn forward and Right motor will turn forward:
  if (digitalRead(Leftsensor) == LOW && digitalRead(Rightsensor) == LOW) {
    digitalWrite(LeftmotorPin1, LOW); // set leg 1 of the H-bridge low
    digitalWrite(LeftmotorPin2, HIGH); // set leg 2 of the H-bridge high
    digitalWrite(RightmotorPin3, LOW); // set leg 1 of the H-bridge low
    digitalWrite(RightmotorPin4, HIGH); // set leg 2 of the H-bridge high
  }
  
  // if Left sensor is 1 and Right sensor is 0, Left motor will turn forward and Right motor will stop:
  else if (digitalRead(Leftsensor) == HIGH && digitalRead(Rightsensor) == LOW){
    digitalWrite(LeftmotorPin1, LOW); // set leg 1 of the H-bridge low
    digitalWrite(LeftmotorPin2, HIGH); // set leg 2 of the H-bridge low
    digitalWrite(RightmotorPin3, LOW); // set leg 1 of the H-bridge low
    digitalWrite(RightmotorPin4, LOW); // set leg 2 of the H-bridge high
    delay(20);
  }
  
  // if Left sensor is 0 and Right sensor is 1, Left motor will stop and Right motor will turn forward:
  else if (digitalRead(Leftsensor) == LOW && digitalRead(Rightsensor) == HIGH){
    digitalWrite(LeftmotorPin1, LOW); // set leg 1 of the H-bridge low
    digitalWrite(LeftmotorPin2, LOW); // set leg 2 of the H-bridge low
    digitalWrite(RightmotorPin3, LOW); // set leg 1 of the H-bridge low
    digitalWrite(RightmotorPin4, HIGH); // set leg 2 of the H-bridge high
    delay(20);
  }
  
  // if Left sensor is 1 and Right sensor is 1, the motors will stop:
  else if (digitalRead(Leftsensor) == HIGH && digitalRead(Rightsensor) == HIGH){
    digitalWrite(LeftmotorPin1, LOW); // set leg 1 of the H-bridge low
    digitalWrite(LeftmotorPin2, LOW); // set leg 2 of the H-bridge low
    digitalWrite(RightmotorPin3, LOW); // set leg 1 of the H-bridge low
    digitalWrite(RightmotorPin4, LOW); // set leg 2 of the H-bridge high
   }
  
}

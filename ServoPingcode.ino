// code for pan_tilt servo with ping sensor
#include <Servo.h> // the "servo" library is opean girl

Servo myservo;
Servo myservo2;

int pos = 90; // start position

const int sensorMin = 0;      // sensor minimum, discovered through experiment
const int sensorMax = 80;    // sensor maximum, discovered through experiment
const int pingPin = 7;
int distance;

void setup() {
   // initialize serial communication:
  Serial.begin(9600); 
}
void loop() {
    long duration,cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  distance = (duration,cm);
      // map the sensor range to a range of four options:
       int range = map(distance, sensorMin, sensorMax, 0, 2);
  switch (range) {
  case 0:    // 
    Serial.println(" CLOSE ");
    myservo.attach(9);
    myservo2.attach(10);
    for(pos = 100; pos >= 0; pos --) // goes from 0 degrees to 100 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo2.write(100-pos); 
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 0; pos <= 100; pos ++)     // goes from 100 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo2.write(100-pos);
    delay(5);                       // waits 15ms for the servo to reach the position 
  } 
   
    break;
  case 1:    // 
    Serial.println(" NEAR ");
    myservo.attach(9);
    myservo2.attach(10);
    for(pos = 100; pos >= 0; pos --) // goes from 0 degrees to 100 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo2.write(100-pos); 
    delay(20);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 0; pos <= 100; pos ++)     // goes from 100 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    myservo2.write(100-pos);
    delay(20);                       // waits 15ms for the servo to reach the position 
  } 
   
     break;
   case 2:    // 
     Serial.println(" IS SOMEONE THERE? ");
     myservo.detach();
     myservo2.detach();
      break;
  }
}
long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}


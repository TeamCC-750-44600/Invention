#include <Servo.h>
#include <Stepper.h> //import stepper motor library

const int forward = 12;
const int backward = 11;

const int trig = A2;
const int echo = A1;

int duration;
int distance;

Servo stir;

const int stepsPerRevolution = 2048;
Stepper belt (stepsPerRevolution, 8, 7, 6, 5);

void setup() {  
  belt.setSpeed(18);
  stir.attach (10);
  Serial.begin (115200);
  Serial.println("In the setup. Starting now...");
  stir.write(0);
  pinMode(trig, OUTPUT);
  pinMode( echo, INPUT);
}

void loop() {
    digitalWrite (trig, HIGH);
    delayMicroseconds (10);
    digitalWrite (trig, LOW);
    duration = pulseIn (echo, HIGH);
    distance = (duration * 0.034) / 2;  
    Serial.print (distance);
    Serial.println ("cm");

  if (distance < 5) {
    
   Serial.println ("new object detected");
   belt.step(stepsPerRevolution * 5);
   Serial.println ("belt has turned");
   digitalWrite (backward, HIGH);
   Serial.println ("0 ml");
   delay (8000);
   digitalWrite (backward, LOW);
   Serial.println ("6.68 ml");
   }

  stir.write (180);
  Serial.println("180°");
  delay (1800);
  stir.write (0);
  Serial.println("0°");
  delay(1800);
}

// import the servo library
#include <Servo.h>

// create the object "servoSG90" in the Servo.h library
Servo servoSG90;

// Variable for analog in 0 to potentiometer
int const potPin =  A0;

// Declare potentiometer value as int
int potVal;

// Declare servo angle as int
int angle;

void setup() {
  // Assign servo object to digital pin 9
  servoSG90.attach(9);
  
  // set serial communication to baud 9600
  Serial.begin(9600);
}
void loop() {
  // read analog input of potentiometer and assign to vaiable "potVal"
  potVal = analogRead(potPin);
  
  // print results to terminal
  Serial.print("Pot Value: ");
  Serial.print(potVal);
  
  // re-map ADC input to angle degree output
  angle = map(potVal, 0, 1023, 0, 179);
  
  //print results to terminal
  Serial.print(", Angle: ");
  Serial.println(angle);
  
  // command servo to rotate to angle
  servoSG90.write(angle);
  
  // repeat loop after a short time
  delay(15);
}

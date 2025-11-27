int const potPin = A0;
int const driverIn2 = 2;
int const driverIn1 = 3;
int const button1 = 4;
int const button2 = 5;
int const enableDriver = 9;


void setup() {
  Serial.begin(9600);
  
  pinMode(potPin, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(enableDriver, OUTPUT);

}

void loop() {
  int potPosition = analogRead(potPin);
  int potPWM= map(potPosition, 0, 1023, 0 , 255);
  
  analogWrite(enableDriver, potPWM);
  int button1Status = digitalRead(button1);
  int button2Status = digitalRead(button2);

  if(button1Status == HIGH){
    digitalWrite(driverIn2, LOW);
    digitalWrite(driverIn1, HIGH);
  }
  else if(button2Status == HIGH){
    digitalWrite(driverIn1, LOW);
    digitalWrite(driverIn2, HIGH);
  }
  else if(button1Status == LOW && button2Status == LOW){
    digitalWrite(driverIn1, LOW);
    digitalWrite(driverIn2, LOW);
  }
}

int switchPin = 2;
int motorPin = 9;
int switchState = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(switchPin, INPUT);
  pinMode(motorPin, OUTPUT);

}

void loop() {
  switchState = digitalRead(switchPin);

  Serial.println(switchState);

  if (switchState == HIGH){
    digitalWrite(motorPin, HIGH);
  }
  else{
    digitalWrite(motorPin, LOW);
  }

}

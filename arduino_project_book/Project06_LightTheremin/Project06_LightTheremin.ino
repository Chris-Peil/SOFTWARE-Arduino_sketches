// Variable setup
int sensorValue;

// sensorLow refers to both the lower light and lower voltage drop across photoresistor.
// There is an inverse relationship between voltage and light, thus maximum ADC values are as follows:
int sensorLow = 1023;
int sensorHigh = 0;

// pin 13 is the onboard LED pin. Used here as a status LED.
const int ledPin = 13;


void setup() {
  Serial.begin(9600);
  
  // Set onboard LED to HIGH
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  // while it is within 5 seconds of startup
  while (millis() < 5000){
    
    // Calibrate photoresistor ADC values to the surrounding light.
    sensorValue = analogRead(A0);
    if (sensorHigh > sensorValue){
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow){
      sensorLow = sensorValue;
    }
  }

  // Set onboard LED low when calibration is finished
  digitalWrite(ledPin, LOW);
  Serial.print("sensorHigh: ");
  Serial.print(sensorHigh);
  Serial.print(", sensorLow: ");
  Serial.println(sensorLow);
}

void loop() {
  // Read ADC value of photoresistor
  sensorValue = analogRead(A0);

  // mappitch based upon most recent ADC reading
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // if no interation to phototransistor turn speaker off, else make noise.
  if (sensorValue >= sensorLow - 10){
    noTone(8);
  }
  else{
    tone(8, pitch, 20);
  }
  
  delay(10);

}

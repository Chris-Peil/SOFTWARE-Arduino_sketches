// Tilt switch pin
const int switchPin = 8;

// Time passed status variable
unsigned long previousTime = 0;

// Tilt switch status variables
int currentSwitchState = 0;
int previousSwitchState = 0;

// Using digital pins 2 to 7
int LEDPinStart = 2;
int LEDPinStop = 7;

// Current set for 5 seconds
unsigned long LEDInterval = 5000;

// LED pin position
int LEDCount = LEDPinStart;

void setup() { 
  Serial.begin(9600);

  // Set LED pins as outputs
  for(int i = LEDPinStart; i < LEDPinStop+1; i++){
    pinMode(i, OUTPUT);
  }

  // Set tilt switch pin as input
  pinMode(switchPin, INPUT);
  

}

void loop() {
  // Set current time in milliseconds
  unsigned long currentTime = millis();
  
  // If time passed is great than LED intervals, turn on next LED
  if (currentTime - previousTime > LEDInterval){
    previousTime = currentTime;
    digitalWrite(LEDCount, HIGH);
    
    Serial.println(LEDCount, "LED ON");
    LEDCount += 1;

    if (LEDCount == LEDPinStop){

    } 
  }

  // Check current switch state if it has changed
  currentSwitchState = digitalRead(switchPin);
  
  // If switch state changed than reset LEDs and time
  if (currentSwitchState != previousSwitchState){
    for(int i = LEDPinStart; i < LEDPinStop+1; i++){
      digitalWrite(i, LOW);
    }
    LEDCount = LEDPinStart;
    previousTime = currentTime;
    
    Serial.println("LED OFF");
  }

  // Re-set switch state for next loop cycle
  previousSwitchState = currentSwitchState;
}

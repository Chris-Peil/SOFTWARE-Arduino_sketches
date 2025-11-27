uint8_t level = 0;

int function_gen = 3;

int valSin; // the sinwave variable

void setup()
{
//Serial.begin(9600);
DDRD = B11111111; // set all Digital Pins on PORTD to OUTPUT
}

void loop()
{
  switch(function_gen){
    case 0:
      //Rectangle
      PORTD = 255;  // 255 is 11111111 in binary
      delay(1);
      PORTD = 0;	// 0 is 00000000 in binary
      delay(1);

      break;
     case 1: 
      //Sawtooth
      level = level % 255;
      PORTD = level++;

      break;
    case 2:
      //Triangle
      for(int i = -255 ; i < 255 ; i++){
      PORTD = abs(i);
      }

      break;
    case 3:
      //Sine
      for (int i = 0; i < 360; i++) { //looping the value of i from 0 to 360 degree
        valSin = ((sin(i * DEG_TO_RAD) + 1) * 255) / 2; // creating the sinwave from i, 255 is the highest value in 8 bit (0-255)
        PORTD = valSin; // assign the sinwave to PORTD
      }

      break;
  } 
}
/*
/////////////////////////////////////
//  Mid-Term WIP //
////////////////////////////////////
- Start with a random number
- Guess the number using the potentiometer 
- A light will turn on indicating if you were right or wrong 
*/

#include <cmath>

const int LEDPin[]={4,5,6};//Pins for the LED currents 
const int buttonPin1 = 1;//Pin that connects to the button 
const int potPin = 2;//Pin that connects to the Potentiometer

const int pPin = 8;//input pin
bool intro = 0;//beginning 
int octave = 1; 
int octaveT = 4; //T = 2

int maxNum = 3876; //This is the maximum number you can guess 

int gNum = 0; //Guess Number - Set to a random number everytime loop starts up 


void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
   analogReadResolution(12);

  for(int i = 0; i < 3;i++)
  {
      pinMode(LEDPin[i], OUTPUT); 
  }

  Serial.begin(115200);

  gNum = random(0,maxNum);

}


void loop() {

  bool b1 = !digitalRead(buttonPin1); //...use LOGICAL NOT ! to flip the bit
  int adcVal = analogRead(potPin);  //read current analog voltage value @ potPin and store in variable
 //print ADC value to serial monitor



    int light = std::abs(gNum - adcVal);
    if(light > 255){
      light = 255;
    }

    //Serial.println(light);

    analogWrite(LEDPin[2],light);
    // delay(500);

  //Serial.printf("Guess a number between %i and 0... ", maxNum);
  //delay(1000);

  // Serial.println(adcVal);
  // delay(500);

  if(b1)
  {
    if(adcVal <= gNum+20 && adcVal >= gNum-20)
    {
      Serial.println("Correct!");

      digitalWrite(LEDPin[1], HIGH);

       tone(pPin,120*octaveT,500);
      delay(500);
    }

    else
    {
      Serial.println("Wrong!");
      
      digitalWrite(LEDPin[0], HIGH);

      tone(pPin,80*octave,500);
      delay(800);
    }
  }

  delay(10);

  //Serial.println(gNum);

  // Serial.printf("Button 1 = %i | Button 2 = %i \n", b1);
  
  

}
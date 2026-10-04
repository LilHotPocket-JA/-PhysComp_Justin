/*
/////////////////////////////////////
//  Mid-Term WIP //
////////////////////////////////////
- Start with a random number
- Guess the number using the potentiometer 
- A light will turn on indicating if you were right or wrong 
*/

const int LEDPin[]={4,5};//Pins for the LED currents 
const int buttonPin1 = 1;//Pin that connects to the button 
const int potPin = 2;//Pin that connects to the Potentiometer

int maxNum = 341; //This is the maximum number you can guess 

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
   analogReadResolution(12);

  for(int i = 0; i < 2;i++)
  {
      pinMode(LEDPin[i], OUTPUT); 
  }

  Serial.begin(115200);

}


void loop() {
  //since we're using INPUT_PULLUP, pushbutton will read as 1 when OFF
  //if you want the logic to follow the standard ON = 1, OFF = 0...
  int gNum = rand() % maxNum; //Guess Number - Set to a random number everytime loop starts up 

  bool b1 = !digitalRead(buttonPin1); //...use LOGICAL NOT ! to flip the bit
  int adcVal = analogRead(potPin);  //read current analog voltage value @ potPin and store in variable
 //print ADC value to serial monitor

  Serial.println("Guess a number between " + maxNum + "  and 0...");
  delay(1000);

  Serial.println(adcVal/12);
  delay(500);

  if(b1)
  {
    if((adcVal/12) == gNum)
    {
      Serial.println("Correct!");
      digitalWrite(LEDPin[0], HIGH);
    }

    else
    {
      Serial.println("Wrong!");
      digitalWrite(LEDPin[1], HIGH);
    }
  }

  // Serial.printf("Button 1 = %i | Button 2 = %i \n", b1);
  
  

}
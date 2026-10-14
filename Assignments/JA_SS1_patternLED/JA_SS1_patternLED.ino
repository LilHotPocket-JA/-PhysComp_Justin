

//DECLARE GLOBAL VARIABLES UP HERE
const int ledPins[] = {4, 5, 6};  //constant integer  array to ittarate between differen sets of LED pin #'s
int ms = 250;           //integer variable storing delay amount
bool ledState = 0;      //boolean [1-bit] variable storing ledState

void setup() //runs once at start-up [power on or reset button]
{    
  for (int i = 0; i < 3; i++) {  //set voltage of every variable 
    pinMode(ledPins[i], OUTPUT);  //set LED pin to output voltage
  }

  Serial.begin(9600);
}


void loop() //loop function runs forever
{ //START OF LOOP
  
  //Pattern 1
  
  for(int i = 0; i < 3; i++){ 
    digitalWrite(ledPins[i], 1); //set LED pin to HIGH, 3.3V
    delay(ms); 
    digitalWrite(ledPins[i], 0);  //set LED pin to LOW, 0V
   delay(ms); 
  }  
  delay(ms); 

  //Pattern 2
  
  for(int i = 0; i < 3; i++){ 
    digitalWrite(ledPins[i], LOW); //set LED pin to HIGH, 3.3V
    delay(500);  //wait 500 milliseconds
    digitalWrite(ledPins[i], HIGH);  //set LED pin to LOW, 0V
   delay(500);  //wait 500 milliseconds
  }  
  delay(1000); 

  //Pattern 3
  
  for(int i = 3; i > 0; i--){ 
    digitalWrite(ledPins[i], 1); //set LED pin to HIGH, 3.3V
    delay(ms); 
    digitalWrite(ledPins[i], 0);  //set LED pin to LOW, 0V
   delay(ms); 
  }  
  delay(ms); 

  //Pattern 4
  int count = 0;
    while(count < 2){
      digitalWrite(ledPins[1], 1);
    digitalWrite(ledPins[0], 1);
    digitalWrite(ledPins[2], 1);
    delay(ms);  
    digitalWrite(ledPins[1], 0);
    digitalWrite(ledPins[0], 0);
    digitalWrite(ledPins[2], 0);
    delay(ms); 
    count++; 
    }
    delay(500);
    

} // END OF LOOP [will begin again from start of loop]
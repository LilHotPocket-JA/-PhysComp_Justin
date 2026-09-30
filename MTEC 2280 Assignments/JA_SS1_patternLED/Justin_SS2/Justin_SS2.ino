

const int buttonPin = 54;
int count; 


const int ledPins[] = {4, 5, 6, 7};  
int ms = 250;          
bool ledState = 0;      


void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  for (int i = 0; i < 4; i++) {  //set voltage of every variable 
  pinMode(ledPins[i], OUTPUT);  //set LED pin to output voltage
  }
 
  Serial.begin(115200);

}

void loop() {
    bool b1 = digitalRead(buttonPin);

    Serial.println(b1);

    if(b1){
      count++;
    }

    else if(count > 5){
      count = 1;
    }
  
    switch(count){
      case 1: //Sets them all off 
        for(int i = 0; i < 4; i++){ 
        digitalWrite(ledPins[i], 0);  
        }  
      break;

      case 2: //Turns all of them on 
        for(int i = 0; i < 4; i++){ 
          digitalWrite(ledPins[i], 1);  
        }  
      break;

      case 3: //Moves in a gradient 
        for(int i = 0; i < 4; i++){ 
          digitalWrite(ledPins[i], 1);
          digitalWrite(ledPins[i]-1, 0);  
          delay(500);
        }  
      break;

      case 4: //Does it backward 
        for(int i = 4; i > 0; i--){ 
          digitalWrite(ledPins[i], 1);
          digitalWrite(ledPins[i]+1, 0);  
          delay(500);
        }  
      break;

      case 5://Blinks 
          count = 0; 

          while(count < 2)
          {
            digitalWrite(ledPins[4], 1);
            digitalWrite(ledPins[5], 1);
            digitalWrite(ledPins[6], 1);
            digitalWrite(ledPins[7], 1);
            delay(250);
            digitalWrite(ledPins[4], 0);
            digitalWrite(ledPins[5], 0);
            digitalWrite(ledPins[6], 0);
            digitalWrite(ledPins[7], 0);
            delay(500);
          }
      break;
      
      default:
      break;
    }

}
/* 
first draft for a temperature control device
on arduino micro board

created 2014
by Daniel & Lisa

This code is published under GPL v2
*/

const int LedPins[5] = {2, 3, 4, 5, 6};
const int RelaisPin  = 11;
const int TempPin    = A5;
const int Slope      = 1;
const int Offset     = 250;
const int LedThreshold[] = {200, 210, 220, 230, 240};
const int TempThreshold  = 250;

void setup() 
{
  for (int i = 0; i < 5; i++) 
    pinMode(LedPins[i], OUTPUT);    

  pinMode(RelaisPin, OUTPUT);    
  pinMode(TempPin, INPUT);
}

int checkSensor()
{
  int sensorValue = analogRead(TempPin); 
  int temp        = Slope * sensorValue - Offset;
  return temp;
}

// persistent storage fo user settings
// anti-hysterese
// security switch off 

void loop()
{
  int temperature = checkSensor();
  
  for (int i = 0; i < 5; i++) 
    digitalWrite(LedPins[i], temperature > LedThreshold[i]);
    
  digitalWrite(RelaisPin, temperature < TempThreshold);
  
} 


  






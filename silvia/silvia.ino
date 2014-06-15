/* 
first draft for a temperature control device
on arduino micro board

created 2014
by Daniel & Lisa

This code is published under GPL v2
*/

const int LedPins[]  = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const int RelaisPin  = 11;  // heater
const int TempPin    = A5;
//const int WaterPin   = A5;
const int PotzPin    = A4;
const int Slope      = 1;
const int Offset     = 0;
const int LedThreshold[] = {450, 470, 490, 510, 530, 550, 570};
const int HeaterThreshold  = 250;
//const int  = 4868;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void setup() 
{
  for (int i = 0; i < ARRAY_SIZE(LedPins); i++) 
    pinMode(LedPins[i], OUTPUT);    

  pinMode(RelaisPin, OUTPUT);    
  pinMode(TempPin, INPUT);
}

/*
int securityCheck(int temp, int Threshold)
{
  if (temp < Threshold) {
    
  }
  
  return temp;
}
*/

int checkTSensor()
{
  int sensorValue = analogRead(TempPin); 
  int temp        = Slope * sensorValue - Offset;
  return temp;
}

/*
int checkWaterSensor()
{
  int waterLevel = analogRead(WaterPin); 
  return waterLevel;
}
*/

// persistent storage fo user settings
// anti-hysterese
// security switch off 

void loop()
{
  
  int potzValue = analogRead(TempPin); 
//  digitalWrite(LedPins[7], HIGH);
//  digitalWrite(LedPins[8], HIGH);

    
  for (int i = 0; i < ARRAY_SIZE(LedPins); i++) 
    digitalWrite(LedPins[i], (potzValue & (1 << (i + 1))) ? 1:0);

   delay(1000);
    
  return;
  
  int temperature = checkTSensor();
  
  for (int i = 0; i < ARRAY_SIZE(LedPins); i++) 
    digitalWrite(LedPins[i], temperature > LedThreshold[i]);
    
  digitalWrite(RelaisPin, temperature < HeaterThreshold);
  
} 


  






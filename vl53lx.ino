#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;


const int type = 1;// 1=mm , 2= cm
String unit;// variable for unit, mm or cm
void setup()
{

  Serial.begin(9600);
  Wire.begin();

  sensor.init();
  sensor.setTimeout(500);

  // Start continuous back-to-back mode (take readings as
  // fast as possible).  To use continuous timed mode
  // instead, provide a desired inter-measurement period in
  // ms (e.g. sensor.startContinuous(100)).
  sensor.startContinuous();
 
}

void loop()
{
  int distance =sensor.readRangeContinuousMillimeters();
  //int distance =sensor.startContinuous(100);

 //distance = distance;
  Serial.print("Distance: ");


  if(type ==2){
    float distanceCM = (float) (distance/10.0);
      unit ="cm";
      Serial.print(distanceCM);
      Serial.print(unit);      
    }else{
    unit ="mm";
      Serial.print(distance);
      Serial.print(unit);       
    }  

  lcd.print(unit);    
  
  if (sensor.timeoutOccurred()) { Serial.print(" TIMEOUT"); }

  Serial.println();
  delay(100);
} 

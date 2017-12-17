#include <BH1750.h>
#include <Wire.h>

BH1750 lightSensor;
unsigned long sampleTimer = 0;
unsigned long sampleInterval = 100; //100 ms = 10Hz rate

void setup()
{

  Serial.begin(9600);
  Wire.begin();

  lightSensor.begin(BH1750_CONTINUOUS_HIGH_RES_MODE);// Measurement time is approx 120ms.
  Serial.println(F("Light Intensity"));

}

void loop() 
{
  uint16_t lux = lightSensor.readLightLevel();
  unsigned long currMillis = millis();
  if(currMillis - sampleTimer >= sampleInterval)
  {
     sampleTimer = currMillis; 
     Serial.print("Light: ");
     Serial.print(lux);
     Serial.println(" lx"); 
  }
  
  delay(1000); //delay of 1 sec

}

#include "SoftI2CMaster.h"
#define addressTemp 0x48
#include <LiquidCrystal.h>
const byte sdaPin = 17;
const byte sclPin = 16;
SoftI2CMaster i2c = SoftI2CMaster( sdaPin,sclPin );
LiquidCrystal lcd(1, 2, 0, 31, 30, 29, 28, 27, 26, 25, 24);

/** Setup Funktion - Standardmäßig von Arduino aufgerufen     
 *  @see arduino.h  
 */
void setup()
{
  Serial.begin(9600);
  Serial.println("Gemini Temperature");
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("-_-_-_-_-_-_-_-");
  lcd.setCursor(0,1);
  lcd.print("Gemini Light");
  lcd.setCursor(0,0);
  delay(5000);
  lcd.clear();
}

/** Loop Funktion - Standardmäßig von Arduino aufgerufen     
 *  @see arduino.h  
 */
void loop()
{
  Serial.println (temp());
  delay(100);
  lcd.setCursor(0,0);
  lcd.print("Gemini Light !");
  lcd.setCursor(0,1);
  lcd.print(temp());
  lcd.print(char(223));
}

/** I2C Übergabe Temperatur    
 *  @return Die Summe der beiden Zahlen a und b.  
 *  @see SoftI2CMaster  
 */
int temp()
{
  int temperature;
  
  i2c.beginTransmission(addressTemp);
  i2c.send(0x00);
  i2c.requestFrom(addressTemp);
  temperature = i2c.receive();
  i2c.endTransmission();
  
  return temperature;
}



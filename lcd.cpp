#include <LCD_I2C.h> // LCD_I2C
#include <Arduino.h>

LCD_I2C lcd(0x27);

void setupLCD()
{
  lcd.begin();
  lcd.backlight();
  lcd.print("Air Quality");
  lcd.setCursor(0, 1);
  lcd.print("Monitoring (*_*)");
  delay(1000);
}

void displayInfo(String s)
{
  lcd.clear();
  lcd.print(s);
}

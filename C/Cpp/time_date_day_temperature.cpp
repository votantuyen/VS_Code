#include<DS3231.h>
#include"LiquidCrystal_I2C.h"

DS3231 rtc(SDA,SCL);
LiquidCrystal_I2C lcd(0x27,20,4);

void setup
{
    rtc.begin();
    lcd.init();
    lcd.backlight();
}

char temF[6];
float temperature;

void loop()
{
    char * str;

    str = rtc.getTimestrAMPM();
    lcd.setCursor(0,0);
    lcd.print("Time: ");
    lcd.print(str);

    str = rtc.getDateStr();
    lcd.setCursor(0,1);
    lcd.print("Date: ");
    lcd.print(str);

    str = rtc.getDOWStr();
    lcd.setCursor(0,0);
    lcd.print("Day: ");
    lcd.print(str);

    lcd.setCursor(0,3);
    lcd.print("Temperature: ");
    Temperature = rtc.getTemp();
    dtostrf(Temperature,5,1,temF);

    lcd.print(temF);
    lcd.print((char)223);
    lcd.print("C");

    delay(1000);
}
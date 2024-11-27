//DHT
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Arduino.h>

//icd
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 12     
#define DHTTYPE   DHT22     

DHT dht(DHTPIN, DHTTYPE);

int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup() {
  Serial.begin(9600);
  Serial.println("THitirat");
    dht.begin();
lcd.init();
  lcd.backlight();

}
void loop() {
  delay(500);
  
  float h =dht.readHumidity();
  float t =dht.readTemperature();
  if (isnan(h) || isnan(t)) {
  Serial.println("Failed to read from DHT sensor!");
  return;
  }
  lcd.setCursor(0,0);
  lcd.print("Humi=     " + String(h));
  lcd.setCursor(13,0);
  lcd.print("%     " + String(h));
   lcd.setCursor(0,1);
  lcd.print("Temp=     " + String(t));
   lcd.setCursor(13,1);
  lcd.print("C     " + String(t));
  delay(1000);
}

#include <dht.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
dht DHT;
#define DHT11_PIN 7
int led = 13; //output voltage for DHT11
void setup(){
  lcd.begin(16, 2);
  pinMode(led, OUTPUT);
}
void loop()
{
  //blinking the LED 
  //digitalWrite(led,HIGH);
  //delay(1000);
  //digitalWrite(led, LOW);
  //delay(1000);
  
  int chk = DHT.read11(DHT11_PIN);
  int humidity = DHT.humidity;
  //lcd screen printing to see data output
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  //turns on or off the water source depending on the range
  //Serial.print(humidity); 
  if(humidity > 73){
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
  delay(1100);
}

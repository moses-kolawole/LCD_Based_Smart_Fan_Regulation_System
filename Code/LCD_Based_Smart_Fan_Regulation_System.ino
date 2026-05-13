#include <LiquidCrystal_I2C.h>

#define potPin A0
#define relayPin 7

int potValue;
int speedLevel;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

  pinMode(relayPin, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Fan Speed Control");
  delay(2000);
  lcd.clear();

}

void loop() {

  potValue = analogRead(potPin);

  // Map to speed levels (0–3)

  if (potValue < 200) {
  lcd.setCursor(0, 0);
  lcd.print("Speed: ");
  lcd.setCursor(4, 1);
  lcd.print("OFF   ");
  digitalWrite(relayPin, LOW);
  }

  else if (potValue >= 200 && potValue <= 800) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Speed: ");
  lcd.setCursor(4, 1);
  lcd.print("LOW  ");
  digitalWrite(relayPin, HIGH);
  delay(2000);
  digitalWrite(relayPin, LOW);
  delay(1000);
  }

  else if(potValue > 800){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Speed: ");
  lcd.print("HIGH   ");
  digitalWrite(relayPin, HIGH);
  delay(5000);
  digitalWrite(relayPin, LOW);
  delay(200);
  }

}
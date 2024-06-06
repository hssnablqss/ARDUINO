
#include<LiquidCrystal.h>
const int LDR_Pin = A0;
const int BUZ_PIN = 7;
const int LED_PIN = 6;
LiquidCrystal lcd(8,9,10,11,12,13);

int state;

void setup() {
  Serial.begin(9600);
  pinMode(LDR_Pin, INPUT_PULLUP);  // Some PIR sensors are open-collector
  pinMode(BUZ_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode (9, OUTPUT);
  pinMode (10, OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {

  int SensorValue = analogRead(LDR_Pin); // read A0
  float Vout = SensorValue * 0.0048;
  Serial.println(Vout);
  delay(250);

   // Map the sensor value to LED brightness
  int brightness = map (SensorValue, 0, 1023, 0, 255);
  analogWrite(LED_PIN, brightness);

  int pot = analogRead(A0);
  pot = map (pot, 0, 1023, 0, 255);

  // Check the PIR sensor
  if (Vout < 2.2) {  // turn everything off
 // noTone(BUZ_PIN);Tone(BUZ_PIN);
  digitalWrite(LED_PIN,HIGH); // Fix the syntax error here

  analogWrite(9,(0,255));
  analogWrite(10,(0,255));
  analogWrite(11,(0,255));
  tone(7,196,125);
  delay(125*1.30);

  analogWrite(9,random(0,255));
  analogWrite(10,random(0,255));
  analogWrite(11,random(0,255));
  tone(7,196,125);
  delay(125*1.30);

  analogWrite(9,random(0,255));
  analogWrite(10,random(0,255));
  analogWrite(11,random(0,255));
  tone(7,220,250);
  delay(250*1.30);

  analogWrite(9,random(0,255));
  analogWrite(10,random(0,255));
  analogWrite(11,random(0,255));
  tone(7,196,250);
  delay(250*1.30);

  analogWrite(9,random(0,255));
  analogWrite(10,random(0,255));
  analogWrite(11,random(0,255));
  tone(7,247,250);
  delay(250*1.30);

  analogWrite(9,random(0,255));
  analogWrite(10,random(0,255));
  analogWrite(11,random(0,255));
  tone(7,247,250);
  delay(250*1.30);
  analogWrite(9,random(0,255));
  analogWrite(10,random(0,255));
  analogWrite(11,random(0,255));
  tone(7,262,250);
  delay(250*1.30);
  lcd.begin(16, 2);
  lcd.print("CUSTOMER IS HERE");
  lcd.setCursor(0, 1);
  lcd.noBlink();
  lcd.noAutoscroll();
  delay(500);
  lcd.clear();

  

  } else {
    noTone(BUZ_PIN);
    digitalWrite(LED_PIN, LOW);
  }
  analogWrite (9, pot);

  Serial.print("sensor value:");
  Serial.print(SensorValue);

}
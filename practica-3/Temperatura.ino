#include <LiquidCrystal.h> // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize the interface pins

int analogPin0 = A0;
int analogPin1 = A1;

void setup() {
     Serial.begin(9600);
     pinMode(analogPin0, INPUT);
     pinMode(analogPin1, INPUT);
     lcd.begin(16, 2);
}
void loop() {
  double lectura0 = analogRead(analogPin0);
  //double lectura1 = analogRead(analogPin1);
  double temp0 = (lectura0 * (50.0 / 1023.0));
  //double temp1 = (lectura1 * (500.0 / 1023.0));
  //tMap = (xPos-511)/512;
  
  Serial.print(lectura0);
  Serial.print(" \t");
  //Serial.print(lectura1);
  //Serial.print(" \t");
  Serial.println(temp0);
  //Serial.print(" \t");
  //Serial.println(temp1);

  lcd.setCursor(1, 0);
  lcd.print("Temp = ");
  lcd.print(temp0);

  delay(200);
  
}

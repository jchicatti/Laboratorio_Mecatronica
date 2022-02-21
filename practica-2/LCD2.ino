#include <LiquidCrystal.h> // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize the interface pins

void setup() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
}

void loop() {
  lcd.setCursor(16, 0);
  lcd.print("Alejandro Garcia Cortez");
  lcd.setCursor(16, 1);
  lcd.print("Josue Domenico Chicatti");
  lcd.scrollDisplayLeft();
  delay(200);
}

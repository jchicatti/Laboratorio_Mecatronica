#include <Servo.h>
#include <LiquidCrystal.h> // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize the interface pins
Servo myservo; // create servo object to control a servo
double val = 0; // variable to read the value from the analog pin
int analogPin = A0;
double vol = 0;
double pos = 0;

void setup() {
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); // setup serial
  lcd.begin(16, 2);
}
void loop() {
    val = analogRead(analogPin);
    vol = val*5.0/1023.0;
   
    pos = map(val,0,1023,0,180);
    myservo.write(pos); // sets the servo position according to the scaled value
    delay(50);
    lcd.setCursor(0, 0);
    lcd.print("Vol");
    lcd.setCursor(8, 0);
    lcd.print(String(vol));
    lcd.setCursor(0, 1);
    lcd.print("Pos");
    lcd.setCursor(8, 1);
    lcd.print(pos);
}

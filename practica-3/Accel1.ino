#include <LiquidCrystal.h> // include the library code:
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // initialize the interface pins

int ap1 = A3;
int ap2 = A4;
int ap3 = A5;

int sv1 = 0;
int ov1 = 0;

int sv2 = 0;
int ov2= 0;

int sv3 = 0;
int ov3= 0;

double g1 = 0;
double g2 = 0;
double g3 = 0;

double theta = 0;

void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
}

void loop() {
  
sv1 = analogRead(ap1);
ov1 = (sv1-338)*90/68;
g1 = sin(radians(ov1));
delay(2);

sv2 = analogRead(ap2);
ov2 = (sv2-333)*90/68;
g2= sin(radians(ov2));
delay(2);

sv3 = analogRead(ap3);
ov3 = (sv3-345)*90/68;
g3 = sin(radians(ov3));

theta = abs(ov3-90);



Serial.print("X = ");
Serial.print(g1);
Serial.print("\t");
Serial.print(ov1);
Serial.print("\t Y = ");
Serial.print(g2);
Serial.print("\t");
Serial.print(ov2);
Serial.print("\t Z = ");
Serial.print(g3);
Serial.print("\t");
Serial.println(ov3);

lcd.setCursor(1, 1);
lcd.print("Theta= ");
lcd.print(theta);

delay(500);
}

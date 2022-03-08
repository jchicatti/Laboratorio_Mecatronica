int analogPin0 = A0;
int analogPin1 = A1; 

double xPos = 0;
double yPos = 0;
double xMap = 0;
double yMap = 0; 

void setup() {
     Serial.begin(9600);
     pinMode(analogPin0, INPUT);
     pinMode(analogPin1, INPUT);
} 

void loop() {
  xPos = analogRead(analogPin0);
  yPos = analogRead(analogPin1);
      
  xMap = (xPos-511)/512;
  yMap = (yPos-511)/512;

  //Serial.print(xPos);
  //Serial.print(" \t");
  Serial.print(xMap);
  Serial.print(" \t");
  //Serial.print(yPos);
  //Serial.print(" \t");
  Serial.println(yMap);
}

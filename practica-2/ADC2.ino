int analogPin = A0; // potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V

double val = 0; // variable to store the value read
double aux = 0;

void setup() {
  Serial.begin(9600); // setup serial
}

void loop() {
  val = analogRead(analogPin); // read the input pin
  Serial.print ("Conversion analogico-digital (V): ");
  aux = val*5/1023;
  Serial.println(aux); // debug value
  delay(500);
}

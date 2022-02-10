
const int r1 = 13;
const int a1 = 12;
const int v1 = 11;
const int r2 = 10;
const int a2 = 9;
const int v2 = 8;


void setup() {
  pinMode(r1, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(v1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(v2, OUTPUT);
}

void loop() {
  digitalWrite(r2, LOW);
  digitalWrite(a1, LOW); 
  digitalWrite(r1, HIGH);
  digitalWrite(v2, HIGH); 
  delay(5000);
  digitalWrite(v2, LOW);
  digitalWrite(a2, HIGH); 
  delay(1000);
  digitalWrite(r1, LOW);
  digitalWrite(a2, LOW); 
  digitalWrite(v1, HIGH);
  digitalWrite(r2, HIGH);
  delay(5000);
  digitalWrite(v1, LOW);
  digitalWrite(a1, HIGH); 
  delay(1000);
}

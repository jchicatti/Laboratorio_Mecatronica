int val = 0;
int Pot = A0;

int Enb = 13;
int Izq = 12;
int Der = 11;

void setup()
{
  pinMode(Enb, OUTPUT);
  pinMode(Izq, OUTPUT);
  pinMode(Der, OUTPUT);
  digitalWrite(Izq, LOW);
  digitalWrite(Der, LOW);
}

void loop() {
  val = analogRead(Pot);
  digitalWrite(Enb, HIGH);
  if(val<512){
    digitalWrite(Der, LOW);
    analogWrite(Izq, (512 - val)/2);
  } else if(val>512){
    digitalWrite(Izq, LOW);
    analogWrite(Der, (val - 512)/2);
  } else{
    digitalWrite(Izq, LOW);
    digitalWrite(Der, LOW);
  }
}

int btn0 = 2;
int btn1 = 3;

int led0 = 4;
int led1 = 5;

int Enb = 13;
int Izq = 12;
int Der = 11;

void setup() {  
  pinMode(btn0, INPUT);
  pinMode(btn1, INPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(Enb, OUTPUT);
  pinMode(Izq, OUTPUT);
  pinMode(Der, OUTPUT);
  digitalWrite(Enb, HIGH); 
}

void loop() {
  if(digitalRead(btn1)==LOW && digitalRead(btn0)==LOW)
  {
    digitalWrite(led1, LOW); 
    digitalWrite(led0, LOW); 
    digitalWrite(Izq, LOW); 
    digitalWrite(Der, LOW); 
   }
  else if(digitalRead(btn1)==LOW && digitalRead(btn0)==HIGH)
  {
    digitalWrite(led1, LOW); 
    digitalWrite(led0, HIGH); 
    digitalWrite(Izq, HIGH); 
    digitalWrite(Der, LOW); 
  }
  else if(digitalRead(btn1)==HIGH && digitalRead(btn0)==LOW)
  {
    digitalWrite(led1, HIGH); 
    digitalWrite(led0, LOW); 
    digitalWrite(Izq, LOW); 
    digitalWrite(Der, HIGH);
  }
  else if(digitalRead(btn1)==HIGH && digitalRead(btn0)==HIGH)
  {
    digitalWrite(led1, HIGH); 
    digitalWrite(led0, HIGH);  
    digitalWrite(Izq, HIGH); 
    digitalWrite(Der, HIGH);
  }
}

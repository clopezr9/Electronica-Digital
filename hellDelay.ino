#define uSW1 37
#define uSW2 36
#define P1 35
#define P2 34
#define P3 33
#define P4 32
#define SM 22
#define BM 23
#define L1 24
#define L2 25
#define L3 26
#define L4 27

unsigned int cont = 1;

void setup()
{
  pinMode(SM, OUTPUT);
  pinMode(BM, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(uSW1, INPUT);
  pinMode(uSW2, INPUT);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  pinMode(P3, INPUT);
  pinMode(P4, INPUT);
  Serial.begin(9600);
}

void loop(){
   while(cont<=3){
    if(digitalRead(uSW1)== HIGH){
      digitalWrite(SM,LOW);
      digitalWrite(BM,HIGH);
      delay(500); 
    }else if(digitalRead(uSW2) == HIGH){
      digitalWrite(BM,LOW);
      digitalWrite(SM,HIGH);
      delay(500);
       Serial.println(cont);
      cont++;
   }
    //Serial.println(cont);
      //cont++;
   }
  while(digitalRead(P1)== LOW && digitalRead(P2)== LOW && digitalRead(P3)== LOW && digitalRead(P4)== LOW){
    digitalWrite(L1,HIGH);
    delay(500);
    digitalWrite(L2,HIGH);
    delay(500);
    digitalWrite(L3,HIGH);
    delay(500);
    digitalWrite(L4,HIGH);
    delay(500);
    digitalWrite(L1,LOW);
    delay(500);
    digitalWrite(L2,LOW);
    delay(500);
    digitalWrite(L3,LOW);
    delay(500);
    digitalWrite(L4,LOW);
    delay(500);
  }
}

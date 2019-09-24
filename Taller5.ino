#define pA  2
#define pB  3
#define pC  4
#define pD  5
#define pE  6
#define pF  7
#define pG  8
#define LR 23   //Los leds conectados a pines analogos
#define LG 24
#define LB 22
#define ST 12

int temp;
unsigned int dis = 0;

void setup() {
  pinMode(pA,OUTPUT);
  pinMode(pB, OUTPUT);
  pinMode(pC,OUTPUT);
  pinMode(pD,OUTPUT);
  pinMode(pE,OUTPUT);
  pinMode(pF,OUTPUT);
  pinMode(pG,OUTPUT);
  pinMode(LR,OUTPUT);
  pinMode(LB,OUTPUT);
  pinMode(LG,OUTPUT);
  pinMode(ST,INPUT);

  digitalWrite(pA,LOW);
  digitalWrite(pB,LOW);
  digitalWrite(pC,LOW);
  digitalWrite(pD,LOW);
  digitalWrite(pE,LOW);
  digitalWrite(pF,LOW);
  digitalWrite(pG,LOW);
  digitalWrite(LR,LOW);
  digitalWrite(LG,LOW);
  digitalWrite(LB,LOW);


  Serial.begin(9600);
}

void truthTable(unsigned int num) {
  switch (num) {
  case 1:
    digitalWrite(pA, LOW);
    digitalWrite(pB, HIGH);
    digitalWrite(pC, HIGH);
    digitalWrite(pD, LOW);
    digitalWrite(pE, LOW);
    digitalWrite(pF, LOW);
    digitalWrite(pG, LOW);
    break;

    case 2:
    digitalWrite(pA, HIGH);
    digitalWrite(pB, HIGH);;
    digitalWrite(pC, LOW);
    digitalWrite(pD, HIGH);
    digitalWrite(pE, HIGH);
    digitalWrite(pF, LOW);
    digitalWrite(pG, HIGH);
    break;

    case 3:
    digitalWrite(pA, HIGH);
    digitalWrite(pB, HIGH);
    digitalWrite(pC, HIGH);
    digitalWrite(pD, HIGH);
    digitalWrite(pE, LOW);
    digitalWrite(pF, LOW);
    digitalWrite(pG, HIGH);
    break;;

    case 4:
    digitalWrite(pA, LOW);
    digitalWrite(pB, HIGH);
    digitalWrite(pC, HIGH);
    digitalWrite(pD, LOW);
    digitalWrite(pE, LOW);
    digitalWrite(pF, HIGH);
    digitalWrite(pG, HIGH);
    break;;

    case 5:
    digitalWrite(pA, HIGH);
    digitalWrite(pB, LOW);
    digitalWrite(pC, HIGH);
    digitalWrite(pD, HIGH);
    digitalWrite(pE, LOW);
    digitalWrite(pF, HIGH);
    digitalWrite(pG, HIGH);
    break;

    case 6:
    digitalWrite(pA, HIGH);
    digitalWrite(pB, LOW);
    digitalWrite(pC, HIGH);
    digitalWrite(pD, HIGH);
    digitalWrite(pE, HIGH);
    digitalWrite(pF, HIGH);
    digitalWrite(pG, HIGH);
    break;;

    case 7:
    digitalWrite(pA, HIGH);
    digitalWrite(pB, HIGH);
    digitalWrite(pC, HIGH);
    digitalWrite(pD, LOW);
    digitalWrite(pE, LOW);
    digitalWrite(pF, LOW);
    digitalWrite(pG, LOW);;
    break;

    case 8:
    digitalWrite(pA, HIGH);
    digitalWrite(pB, HIGH);
    digitalWrite(pC, HIGH);
    digitalWrite(pD, HIGH);
    digitalWrite(pE, HIGH);
    digitalWrite(pF, HIGH);
    digitalWrite(pG, HIGH);
    break;;

    case 9:
    digitalWrite(pA, HIGH);
    digitalWrite(pB, HIGH);
    digitalWrite(pC, HIGH);
    digitalWrite(pD, HIGH);
    digitalWrite(pE, LOW);;
    digitalWrite(pF, HIGH);
    digitalWrite(pG, HIGH);
    break;;

    case 0:
    digitalWrite(pA, HIGH);
    digitalWrite(pB, HIGH);
    digitalWrite(pC, HIGH);
    digitalWrite(pD, HIGH);
    digitalWrite(pE, HIGH);
    digitalWrite(pF, HIGH);
    digitalWrite(pG, LOW);
    break;
  }
}
  
void loop() {
  temp = analogRead(ST);
    if(temp<= 28){
        analogWrite(LR,255);
        analogWrite(LB,14);
        analogWrite(LG,201);
        Serial.print(temp);
        dis = temp%10;
        truthTable(dis);

      }else if(temp>30 && temp<= 32){
        analogWrite(LR,255);
        analogWrite(LG,128);
        analogWrite(LB,0);
        Serial.print(temp);
        dis = temp%10;
        truthTable(dis);
        
      } else if(temp>32){
        analogWrite(LR,255);
        analogWrite(LG,0);
        analogWrite(LB,0);
        Serial.print(temp);
        dis = temp%10;
        truthTable(dis);
      }
  
}

#define pA  2
#define pB  3
#define pC  4
#define pD  5
#define pE  6
#define pF  7
#define pG  8
#define SW 37
#define LR 23
#define LG 24
#define LB 22

unsigned int cont = 0;
bool estadoAnt;
bool estadoAct;

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
  pinMode(SW,INPUT);

  digitalWrite(pA,LOW);
  digitalWrite(pB,LOW);
  digitalWrite(pC,LOW);
  digitalWrite(pD,LOW);
  digitalWrite(pE,LOW);
  digitalWrite(pF,LOW);
  digitalWrite(pG,LOW);

  digitalWrite(SW,LOW);
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
  estadoAct=digitalRead(SW);
  if((estadoAnt==LOW && estadoAct==HIGH)) {
      cont++;
      delay(5);
    }
  while(digitalRead(SW)== HIGH){
    if(cont<=2) {
      digitalWrite(LB,HIGH);
      digitalWrite(LG, LOW);
      digitalWrite(LR, LOW);
    } else if(cont>=3 && cont<=4) {
      digitalWrite(LG, HIGH);
      digitalWrite(LR, LOW);
      digitalWrite(LB, LOW);
    } else if(cont>4 && cont<7) {
      digitalWrite(LR, HIGH);
      digitalWrite(LG, LOW);
      digitalWrite(LB, LOW);
    } else {
      digitalWrite(LR, HIGH);
      digitalWrite(LB, HIGH);
      digitalWrite(LG, HIGH);
    }

   delay(500);
  }
  estadoAnt = estadoAct;
  if(cont > 9) {
    cont = 0;
    }
  truthTable(cont);
  Serial.println(cont);
}

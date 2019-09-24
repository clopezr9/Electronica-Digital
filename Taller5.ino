#define pA  37
#define pB  36
#define pC  35
#define pD  34
#define pE  33
#define pF  32
#define pG  31
#define LR 5  //Los leds conectados a pines analogos
#define LG 4
#define LB 6
#define ST 3

float temp;
int dis = 0;

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
  temp = (analogRead(ST)*500)/1024;
    if(temp<= 28){
        analogWrite(LR,255);
        analogWrite(LB,14);
        analogWrite(LG,201);
        Serial.println(temp);
        delay(1500);
        dis = ((int)temp)%10;
        truthTable(dis);

      }else if(temp>30 && temp<= 32){
        analogWrite(LR,255);
        analogWrite(LG,128);
        analogWrite(LB,0);
        Serial.println(temp);
        delay(1500);
        dis = ((int)temp)%10;
        truthTable(dis);
        
      } else if(temp>32){
        analogWrite(LR,255);
        analogWrite(LG,0);
        analogWrite(LB,0);
        Serial.println(temp);
        delay(1500);
        dis = ((int)temp)%10;
        truthTable(dis);
      }
  
}

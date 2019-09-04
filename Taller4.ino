#define EV  36
#define BH  37
#define AA  32
#define AB  33
#define SNH 30
#define SNL 28
#define SW  31   //dice 37
#define uSW1 27
#define uSW2 26


unsigned long tmp;
unsigned int period;

void setup() {
  Serial.begin(9600);
  //Inicializacion de sensores y actuadores
  digitalWrite(EV, LOW);
  digitalWrite(BH, LOW);
  digitalWrite(AA, LOW);
  digitalWrite(AB, LOW);
  digitalWrite(SNH, LOW);
  digitalWrite(SNL, LOW);
  digitalWrite(SW, LOW);

  pinMode(EV, OUTPUT);
  pinMode(BH, OUTPUT);
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT);
  pinMode(SNH, INPUT);
  pinMode(SNL, INPUT);
  pinMode(SW, INPUT);


}

void loop() {

  if(digitalRead(SW)==HIGH){
     if(digitalRead(SNL)==HIGH && digitalRead(SNH)==LOW){
        digitalWrite(BH, HIGH);
        digitalWrite(EV, LOW);
        digitalWrite(AA, LOW);
        digitalWrite(AB, LOW);
     }
     else if(digitalRead(SNL)==HIGH && digitalRead(SNH)==HIGH){
         digitalWrite(BH, LOW);  //Apaga la bomba hidraulica
         period = 30000;
        for(int i=0; i<5; i++){
          delay(10000);
          tmp = millis();
          while( (millis()-tmp) < period){
             Serial.println(millis()); 
             if(digitalRead(uSW2)==LOW && digitalRead(uSW1)==LOW ){
               digitalWrite(AA,LOW);
             digitalWrite(AB,HIGH);
              delay(1500); 
             }else if(digitalRead(uSW1)== HIGH){
              Serial.println(":::");
             digitalWrite(AA,LOW);
             digitalWrite(AB,HIGH);
               delay(1500); 
           }else if(digitalRead(uSW2) == HIGH){
            Serial.println(":)");
              digitalWrite(AB,LOW);
               digitalWrite(AA,HIGH);
              delay(1500);
           }//Inicia el agitador
          }
               //delay(30000);
            digitalWrite(AA,LOW);   //Apaga el agitador
             digitalWrite(AB,LOW);
        }
        digitalWrite(EV,HIGH);//Abre electro valvula para vaciar
     }
  }else{
    digitalWrite(EV, LOW);
    digitalWrite(BH, LOW);
    digitalWrite(AA, LOW);
     digitalWrite(AB, LOW);
    digitalWrite(SNH, LOW);
    digitalWrite(SNL, LOW);
    digitalWrite(SW, LOW);
  }
}

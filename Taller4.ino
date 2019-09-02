#define EV  22
#define BH  23
#define AM  24
#define SNH 25
#define SNL 26
#define SW  27

unsigned long tmp;

void setup() {
  //Inicializacion de sensores y actuadores
  digitalWrite(EV, LOW);
  digitalWrite(BH, LOW);
  digitalWrite(AM, LOW);
  digitalWrite(SNH, LOW);
  digitalWrite(SNL, LOW);
  digitalWrite(SW, LOW);

  pinMode(EV, OUTPUT);
  pinMode(BH, OUTPUT);
  pinMode(AM, OUTPUT);
  pinMode(SNH, INPUT);
  pinMode(SNL, INPUT);
  pinMode(SW, INPUT);


}

void loop() {

  if(digitalRead(SW)==HIGH){
     if(digitalRead(SNL)==HIGH && digitalRead(SNH)==LOW){
        digitalWrite(BH, HIGH);
        digitalWrite(EV, LOW);
        digitalWrite(AM, LOW);
     }
     else if(digitalRead(SNL)==HIGH && digitalRead(SNH)==HIGH){
        for(int i=0; i<5; i++){
          delay(10000);
          tmp= millis();        //Para contar los segundos que debe funcionar el agitador(30 sec)
          if(tmp <= 30000){    
            digitalWrite(AM,HIGH);  //Inicia el agitador 
            digitalWrite(BH, LOW);  //Apaga la bomba hidraulica
          }else{
            digitalWrite(AM,LOW);   //Apaga el agitador
          }
          delay(30000);  //Para que funcione??? 
        }
        digitalWrite(EV,HIGH);//Abre electro valvula para vaciar
     }
  }else{
    digitalWrite(EV, LOW);
    digitalWrite(BH, LOW);
    digitalWrite(AM, LOW);
    digitalWrite(SNH, LOW);
    digitalWrite(SNL, LOW);
    digitalWrite(SW, LOW);
  }
}

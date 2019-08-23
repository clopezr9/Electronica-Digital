#define SF 0  // Pin al que va conectado el sensor
#define LR 22   //Pin led rojo
#define LY 23   //Pin led Amarillo
#define LB 24   //Pin led azul
#define LG 25   //Pin led verde

int FSRread;   // Para almacenar el valor del censor

void setup() {
  Serial.begin(9600); //La verdad no se que hace esto
  pinMode(SF, INPUT);
  pinMode (LR, OUTPUT);
  pinMode(LY, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LG, OUTPUT);
}

void loop() {
  FSRread = analogRead(SF);  //Lee el sensor
  
  Serial.println(FSRread);   //Imprime Valor del sensor
  
  if(FSRread<=255){
    digitalWrite(LR, HIGH);   //Prende el led rojo 
  } 
  else if(FSRread<=510){
    digitalWrite(LR,HIGH);
    digitalWrite(LY, HIGH);   //Prende el led amarillo
  } 
  else if(FSRread<=765 ){
    digitalWrite(LR,HIGH);
    digitalWrite(LY, HIGH);
    digitalWrite(LB, HIGH);   //Prende el led azul
  }
  else{
    digitalWrite(LR,HIGH);
    digitalWrite(LY, HIGH);
    digitalWrite(LB, HIGH);   
    digitalWrite(LG, HIGH);   //Prende el led verde
  }
}

#define SF A0  // Pin al que va conectado el sensor
#define LR 2   //Pin led rojo
#define LY 3   //Pin led Amarillo
#define LB 4   //Pin led azul
#define LG 5   //Pin led verde

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
  
  Serial.println(FSRread);
  
  if(FSRread<=255){
    digitalWrite(LR, HIGH);
  } 
  else if(FSRread<=510){
    digitalWrite(LY, HIGH);
  } 
  else if(FSRread<=765 ){
    digitalWrite(LB, HIGH);
  }
  else{
    digitalWrite(LG, HIGH);
  }
}

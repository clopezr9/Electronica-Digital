#define LED22 22
#define LED23 23
#define LED24 24
#define INICIO 37
#define DETENER 36

void setup()
{
  pinMode(LED22, OUTPUT);
  pinMode(LED23,OUTPUT);
  pinMode(LED24, OUTPUT);
  pinMode(INICIO, INPUT);
  pinMode(DETENER, INPUT);
  digitalWrite(LED22, LOW);
  digitalWrite(LED23, LOW);
  digitalWrite(LED24, LOW);
  Serial.begin(9600);
}


void loop(){
  if(digitalRead(INICIO)==HIGH){
    digitalWrite(LED22, HIGH);
    Serial.println("Led 1 encendido");
    delay(5000);
    digitalWrite(LED23, HIGH);
    Serial.println("Led 2 encendido");
    delay(5000);
    digitalWrite(LED24, HIGH);
    Serial.println("Led 3 encendido");
    delay(5000);
    }
  if(digitalRead(DETENER)){
    digitalWrite(LED22, LOW);
    Serial.println("Led 1 apagado");
    delay(5000);
    digitalWrite(LED23, LOW);
    Serial.println("Led 2 apagado");
    delay(5000);
    digitalWrite(LED24, LOW);
    Serial.println("Led 3 APAGADO");
    delay(5000);
    }
  }

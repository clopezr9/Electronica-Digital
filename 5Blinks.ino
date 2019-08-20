#define LED22 22
#define LED23 23
#define LED24 24
#define SW 37
#define DETENER 36

unsigned int cont = 1;

void setup()
{
  pinMode(LED22, OUTPUT);
  pinMode(SW, INPUT);
  digitalWrite(LED22, LOW);
  Serial.begin(9600);
}

void loop(){
  if(digitalRead(SW)== HIGH){
  while(cont<=5){
    digitalWrite(LED22, HIGH);
    delay(500);
    digitalWrite(LED22,LOW);
    delay(500);
    Serial.println(cont);
    cont++;
    }
  }
  }

#define rojo 22
#define amarillo 23
#define verde 24
#define peatonverde 26
#define peatonrojo 27
#define pulsador 37
//unsigned int tinicial
void setup() {
pinMode(rojo, OUTPUT);
pinMode(amarillo, OUTPUT);
pinMode(verde, OUTPUT);
pinMode(peatonverde, OUTPUT);
pinMode(peatonrojo, OUTPUT);
pinMode(pulsador, INPUT);
Serial.begin(9600);
// put your setup code here, to run once:

}

void loop() {
// put your main code here, to run repeatedly:
digitalWrite(verde, HIGH);
digitalWrite(peatonrojo, HIGH);
if(digitalRead(pulsador)== HIGH){
delay(3000);
digitalWrite(verde, LOW);
digitalWrite(rojo, HIGH);
delay(500);
digitalWrite(peatonverde, HIGH);
digitalWrite(peatonrojo, LOW);
delay(1500);
digitalWrite(peatonverde, LOW);
digitalWrite(peatonrojo, HIGH);
delay(500);
digitalWrite(rojo, LOW);
}
}

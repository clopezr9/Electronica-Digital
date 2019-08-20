#define LED 22   // LED 22 para tittilar
#define SWITCH 37   // Switch

void setup() {
  pinMode(SWITCH, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(LED, LOW);
}

void loop() {
  if(digitalRead(SWITCH)== HIGH){
    Serial.println("ON");
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
    delay(500);
    }else{
    Serial.println("OFF");
    }
 }

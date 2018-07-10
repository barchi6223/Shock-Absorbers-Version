int redp =7;
int bulep =8;
int hand =12;
int geeet,red,bule;
void setup() {
  Serial.begin(38400);
  pinMode(redp,INPUT);
  pinMode(bulep,INPUT);
  pinMode(hand,INPUT_PULLUP);
  Serial.println("1111");
}

void loop() {
  red=digitalRead(redp);
  bule=digitalRead(bulep);
  geeet=digitalRead(hand);
  if(red == HIGH){
    Serial.println("red");
    delay(50);
  }  
  if(bule == HIGH){
    Serial.println("bule");
    delay(50);
  }
  if(geeet == HIGH){
    Serial.println("hand");
    delay(50);
  }

}

int hellPin = A4;
int intStartValue;  //基礎值
int intReadValue;   //後續讀的值
int intCountValue;  //計算基礎值與後續讀的值的相差
void setup() {
  pinMode(hellPin, INPUT);
  Serial.begin(9600);
  intStartValue = analogRead(hellPin);
}

void hellDistance(){
  if(intCountValue > 0 && intCountValue<=3){ //25   90     105   110
    Serial.println("0 Cm");
  }else if(intCountValue > 3 && intCountValue <=20){
    Serial.println("接近 0.5 Cm");
  }else if(intCountValue > 20 && intCountValue <=30){
    Serial.println("0.5 CM");
  }else if(intCountValue > 30 && intCountValue <= 85){
    Serial.println("接近 1 CM");
  }else if(intCountValue > 85 && intCountValue <= 95){
    Serial.println("1 CM");
  }else if(intCountValue > 95 && intCountValue <= 100){
    Serial.println("接近1.5 CM");
  }else if(intCountValue >100 && intCountValue <= 107){
    Serial.println("1.5 CM");
  }else if(intCountValue > 107 && intCountValue <= 110){
    Serial.println("接近 2 CM");
  }else{
    Serial.println("2 CM");
  }
}

void loop() {
  intReadValue = analogRead(hellPin);
  intCountValue = abs(intReadValue - intStartValue);
  Serial.println(intCountValue);
  hellDistance();
}

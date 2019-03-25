
void setup() {
  Serial.begin (115200);
  // put your setup code here, to run once:
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

int green_count = 0;
int red_high_count = 0;
int red_low_count = 0;

void loop() {
  Serial.print(red_high_count);
  Serial.print(red_low_count);
  // put your main code here, to run repeatedly:
  // red high=2,low=1
  if (red_high_count < 2 || red_low_count == 1){
    digitalWrite(4,HIGH);
    red_high_count += 1;
    red_low_count = 0;
  }
  else if (red_high_count == 2 || red_low_count < 1){
    digitalWrite(4,LOW);
    red_high_count = 0;
    red_low_count += 1;
  }
  else{
    ;
  }

  // green
  Serial.println(green_count);
  //Serial.println(green_low_count);
  // put your main code here, to run repeatedly:
  // green high=2,low=3
  if (green_count < 2){
    digitalWrite(5,HIGH);
    green_count += 1;
  }
  else if (green_count < 4){
    digitalWrite(5,LOW);
    green_count += 1;
  }
  else{
    digitalWrite(5,LOW);
    green_count = 0;
  }
  // 1秒まつ
  delay(500);
}

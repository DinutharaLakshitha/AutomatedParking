char data;
void setup() {
  // put your setup code here, to run once:

  data = 0;
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    data = Serial.read();
    Serial.println(data);
    
    }else{
      Serial.println(data);
      }

}

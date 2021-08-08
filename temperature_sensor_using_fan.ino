float temp;
int tempPin = A0;// ardunino pin used for temperature sensor
int tempMin = 25;
int tempMax = 70;
int fan = 6;//the pin where fan is connected
int fanSpeed = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(fan, OUTPUT);
pinMode(tempPin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
temp = analogRead(tempPin);
temp = (temp * 5.0 * 100.0)/ 1024.0; // calculate the temperature is celcius
Serial.println(temp);
delay(1000); //delay in between read for stability
if(temp< tempPin) {
  fanSpeed = 0;
  digitalWrite(fan,LOW);
}
if((temp >= tempMin) &&(temp <= tempMax)) {
  fanSpeed = map(temp,tempMin,tempMax,32,255);//the actual speed of the fan
  analogWrite(fan,fanSpeed); //spin the fan at the fanSpeed speed
}
}

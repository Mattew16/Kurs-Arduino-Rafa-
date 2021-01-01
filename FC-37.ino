int rainSensor = A0;
int rainLED = 2;
int dryLED = 3;
int sensorVal;
int sensortrigger = 200;


void setup(){
  Serial.begin(9600);
  pinMode(rainSensor, INPUT);
  pinMode(rainLED, OUTPUT);
  pinMode(dryLED, OUTPUT);
  digitalWrite(rainLED, LOW);
  digitalWrite(dryLED, LOW);
  
}

void loop() {
  int sensorVal = analogRead(rainSensor);
  Serial.print(sensorVal);
  if(sensorVal < sensortrigger){
    Serial.println("Water Detected!");
    digitalWrite(dryLED, LOW);
    digitalWrite(rainLED, HIGH);
  }
  else {
    Serial.println("No Water Detected!");
    digitalWrite(rainLED, LOW);
    digitalWrite(dryLED, HIGH);
  }
  delay(750);
}

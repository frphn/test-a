/* Arduino example code for MaxBotix MB7389 HRXL-MaxSonar-WR weather resistant ultrasonic distance sensor: analog voltage output. More info: www.makerguides.com */
 
#define sensorPin A0
 
unsigned long int acc = 0;
float distance;

 
void setup() {
 Serial.begin(9600);
}
 
void read_sensor() {
 distance = analogRead(sensorPin) * 5;
}
 
void print_data() {
 Serial.print("distance = ");
 Serial.print(distance);
 Serial.println(" mm");
}

void loop() {
  for (int m = 0; m <10; m++) {
    acc = acc + analogRead(sensorPin)*5;
    delay(150);
  }
  distance = acc/10;
  print_data();
  acc =0;
  //delay(1000);
}

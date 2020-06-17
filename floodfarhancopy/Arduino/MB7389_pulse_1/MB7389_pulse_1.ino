// Arduino example code for MaxBotix MB7389 HRXL-MaxSonar-WR weather resistant ultrasonic distance sensor: analog voltage output. More info: www.makerguides.com */
// Example from Maxbotix. Ran on Feather M0 using pin 5. 
  
#define sensorPin 5
long duration = 0;
long distance = 0;

void setup() {
  pinMode(sensorPin,INPUT);
 Serial.begin(9600);
}
 
void read_sensor() {
  duration = pulseIn(sensorPin, HIGH);
  distance = duration;
}
 
void print_data() {
 Serial.print("distance = ");
 Serial.print(distance);
 Serial.println(" mm");
}

void loop() {
  read_sensor();
  print_data();
  delay(1000);
}

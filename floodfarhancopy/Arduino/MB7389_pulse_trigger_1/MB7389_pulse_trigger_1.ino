// Arduino example code for MaxBotix MB7389 HRXL-MaxSonar-WR weather resistant ultrasonic distance sensor: analog voltage output. More info: www.makerguides.com */
// Example from Maxbotix. Ran on Feather M0 using pin 5. 
  
#define readPin 5 // 
#define triggerPin 6 //

long distance = 0;
long duration = 0;

void setup() {
  pinMode(readPin, INPUT);
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  Serial.begin(9600);
  delay(3000);
  Serial.println("Sensor is ready!");
}

void read_sensor() {
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(readPin, HIGH);
  distance = duration; // this is silly
  delay(150); // MB7289 has 6.6hz readout so this limits 
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

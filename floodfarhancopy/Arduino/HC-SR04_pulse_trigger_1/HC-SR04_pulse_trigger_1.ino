// Arduino example code for HC-SR04 ultrasonic sensor. There are multiple versions of this sensor. This is the RCWL-1601 that runs 3-5v.
// Example from adapted from on Feather M0 using pins 5 6.

//#include <Adafruit_SleepyDog.h>

#define trigPin 5 //
#define echoPin 6 // 

long duration, mm, inches;

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin,LOW);
  Serial.begin(9600);
  
//  pinMode(LED_BUILTIN, OUTPUT);
//  digitalWrite(LED_BUILTIN, HIGH); // Show we're awake

}

void read_sensor() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  mm = (duration/2)/2.91;
  inches = (duration/2)/74; 
  delay(150); // MB7289 has 6.6hz readout so this limits
}

void print_data() {
  Serial.print("distance = ");
  Serial.print(mm);
  Serial.print(" mm, ");
  Serial.print(inches);
  Serial.println(" inches");
}

void loop() {
  read_sensor();
  print_data();

//  digitalWrite(LED_BUILTIN,LOW);
//  int sleepMS = Watchdog.sleep();
//  digitalWrite(LED_BUILTIN,HIGH);
  //delay(2000);
}

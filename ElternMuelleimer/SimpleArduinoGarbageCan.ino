// Arduino Micro

#include <Servo.h>  
#include <NewPing.h>

#define TRIGGER_PIN  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

Servo servoblau;

void setup() { 
servoblau.attach(2);
for(int x = 3; x < 8; x++){
  pinMode(x, OUTPUT);
}
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
} 

 
void loop() { 
  if(sonar.ping_cm() < 31){
    servoblau.write(180);
    for(int x = 3; x < 8; x++){
      digitalWrite(x, HIGH);
      delay(1000);
    }
    for(int x = 3; x < 8; x++){
    digitalWrite(x, LOW);
    }
    servoblau.write(90);
    delay(3000);
  }

  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
}

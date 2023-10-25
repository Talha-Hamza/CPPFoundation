
// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

int data0;

int tempPIN = A0;
double tempC = 0.0;

void setup() {
  pinMode(tempPIN,INPUT);
  Serial.begin(9600);
}

void loop() {
  int ADCreading = analogRead(tempPIN);
  tempC = (ADCreading - 620) * 0.0806;
  Serial.print(ADCreading);
  Serial.print(", ");
   Serial.print(tempC);
  Serial.println(" degC");
  //Serial.printf("%4d, %6.3f degC\n",ADCreading,tempC);
  delay(500);
}

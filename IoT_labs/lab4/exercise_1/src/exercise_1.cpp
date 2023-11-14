// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);
// This program will blink the on-board D7 LED at 0.5 Hz. 
// It does not use the delay() function
// Note that there are two state variables -- one to store the next time to toggle
// the LED, and one to store the current LED state (ON/OFF)

int led = D7;  // The D7 on-board LED

// Declaring the state variables as global variables. 
// You could also declare state variables as local static variables inside the loop
// function (preferred).

bool LED_state = FALSE;

// This variable stores the next time to toggle the LED. 
// It will be initialized to 1 second in the future in the first iteration of the loop function
unsigned long int timeToToggleLED;

void setup() {
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    timeToToggleLED = millis() + 1000;
}

void loop() {
    unsigned long int currentTime = millis();  // get the current time

    // Check if it is time to toggle the LED “Are we there yet? Are we there yet? ..."
    if(currentTime > timeToToggleLED){  
        // Time to Toggle!
        LED_state = !LED_state;
        digitalWrite(led, LED_state);

        // Calculate and store the next time to toggle the LED
        timeToToggleLED += 1000;
    }
    
    // The rest of your Photon code goes here
}


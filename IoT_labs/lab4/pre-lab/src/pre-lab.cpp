// This program will toggle the on-board D7 LED on and off every second.
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(DISABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);
// By holding down the button, you temporarily stop the flash and show a constant blue
// light on the D7 LED. However, the way the code is written is not advisable. It stalls
// the loop() function when the button is held down, and if the button is held down for
// too long, it causes a time-out.
// Try it: Hold down the button for about 20 seconds, and you will see that the 
// board loses cloud connectivity and stops breathing cyan.
int led = D7;    // The D7 on-board LED
int button = D3; // This is the input button (use an internal pull-down resistor)
int LedFreqState = 0;   // set to 0 for 0.50 Hz, set to 1 for 0.25 Hz
int prevButton = LOW;   // state variable to store if button was HIGH or LOW last time

void setup() {
    pinMode(led, OUTPUT);
    pinMode(button, INPUT_PULLDOWN);  // INPUT mode with internal pull-down resistor
    Serial.begin(9600);               // Use Serial port for debugging
}

void loop() {
    int curButton = digitalRead(button);
    if(curButton == HIGH && prevButton == LOW){
        // a transition happened -- the user has just pressed the button
        Serial.println("Button press detected.");  //Debugging printout
        
        // change the state of the LED blinking rate
        LedFreqState++;
        if(LedFreqState > 2){  // make sure it changes from 0 --> 1 --> 0 --> ...
            LedFreqState = 0;
        }
    }
    
    prevButton = curButton;   // keep track of previous button state for next time
    Serial.print(curButton);  // Debugging printout
    
    if(LedFreqState == 0){  // Rate 0: 0.5 Hz (on 1 sec, off 1 sec)
        digitalWrite(led, LOW);
        delay(1000);
        digitalWrite(led, HIGH);
        delay(1000);
    }
    
    else if(LedFreqState == 1){ 	              // Rate 1: 0.25Hz (2 secs on, 2 secs off)
        digitalWrite(led, LOW);
        delay(2000);
        digitalWrite(led, HIGH);
        delay(2000);
    }
    else{ // Rate 2: 1 Hz (on 0.5 sec, off 0.5 sec)
        digitalWrite(led, LOW);
        delay(500);
        digitalWrite(led, HIGH);
        delay(500);
    }
}

// Include Particle Device OS APIs
#include "Particle.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(DISABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);


int led = D7;    // The D7 on-board LED
int button = D3; // This is the input button (use an internal pull-down resistor)
int LedFreqState = 0;   // set to 0 for 0.50 Hz, set to 1 for 0.25 Hz
int prevButton = LOW;   // state variable to store if button was HIGH or LOW last time

bool LED_state = FALSE;
unsigned long int timeToToggleLED;
unsigned long int currentTime;

unsigned long int start_time;
unsigned long int elapsed_time;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(button, INPUT_PULLDOWN);  // INPUT mode with internal pull-down resistor
    Serial.begin(9600);               // Use Serial port for debugging
    // digitalWrite(led, LOW);
    timeToToggleLED = millis() + 1000;
}

void loop() {
    int curButton = digitalRead(button);
    unsigned long int currentTime = millis();  // get the current time

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
    // Serial.print(curButton);  // Debugging printout
    
    if(LedFreqState == 0){  
        currentTime = millis();
        if (currentTime >= timeToToggleLED) {
            LED_state = !LED_state;
            digitalWrite(led, LED_state);  
            timeToToggleLED = currentTime + 250;
        }
    }
    else if(LedFreqState == 1){ 	              // 2 secs on, 2 secs off
        currentTime = millis();
        if (currentTime >= timeToToggleLED) {
            LED_state = !LED_state;
            digitalWrite(led, LED_state);  
            timeToToggleLED = currentTime + 500;
        }
    }
    else{ // Rate 2:  3 sec, off 0.5 sec
        currentTime = millis();
        if (currentTime >= timeToToggleLED) {
            LED_state = !LED_state;
            digitalWrite(led, LED_state);  
            timeToToggleLED = currentTime + 1000;
        }
    }
}

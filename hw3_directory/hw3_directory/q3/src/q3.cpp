// Include Particle Device OS APIs
#include "Particle.h"
#include "neopixel.h"

int PIXEL_PIN = D4;
int PIXEL_COUNT = 3;
int PIXEL_TYPE = WS2812;
// int PIXEL_TYPE = WS2812;
// WS2812 NOTE: use WS2812 if you have them

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// setup() runs once, when the device is first turned on
void setup() {
  strip.begin();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
   /* NOTE: Two versions of the color code are specified below for WS2811 and 
             WS2812 neopixels. Use the version according to the type of neopixels in 
             your kit and delete or comment the other version. */
    //Setup some colors, WS2811 version
    // int PixelColorCyan = strip.Color(   0 , 255, 255);
    // int PixelColorRed  = strip.Color(  80,   0,   0);
    // int PixelColorGold = strip.Color(  60,  50,   5);
    //Setup some colors, WS2812 version
    
    for (int i = 0 ; i<251 ; i+=50){
    
    int PixelColorCyan = strip.Color(   0 , 0, i);
    int PixelColorRed  = strip.Color(  0,   i,   0);
    int PixelColorGreen = strip.Color(  i,  0,   0);
    
   
    //Set first pixel to cyan
    strip.setPixelColor(2, PixelColorCyan);
    //set second pixel to red
    strip.setPixelColor(0, PixelColorRed);
    //set third pixel to Gopher Gold!
    strip.setPixelColor(1, PixelColorGreen);
    strip.show();
    delay(1000);  //wait 1sec

   
}
}





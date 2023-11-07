#define COOL 0
#define OFF  1
#define HEAT 2
#define REDALERT 3
int mode = OFF;

// Include Particle Device OS APIs
#include "Particle.h"
#include "neopixel.h"

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);
int tempPIN = A1;
double tempC = 0.0;
int setModeFromString(String inputString);

int PIXEL_PIN = D4;
int PIXEL_COUNT = 1;
// int PIXEL_TYPE = WS2811;
int PIXEL_TYPE = WS2812;
// WS2812 NOTE: use WS2812 if you have them
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);


void setup() {
  pinMode(tempPIN,INPUT);
  Serial.begin(9600);
  Particle.variable("tempC",tempC);
  Particle.function("cF_setMode", setModeFromString);
  strip.begin();
}

void loop() {
    int ADCreading = analogRead(tempPIN);
    tempC = (ADCreading - 620) * 0.0806;
    Serial.print(ADCreading);
    Serial.print(", ");
    Serial.print(tempC);
    Serial.println(" degC");
    //Serial.printf("%4d, %6.3f degC\n",ADCreading,tempC);

    int PixelColorBlue = strip.Color(0 , 0, 255);
    int PixelColorRed  = strip.Color(  0,   255,   0);
    int PixelColorGold = strip.Color(  50,  60,   5);
    int PixelColorOrange = strip.Color(  255,  165,   0);

    if (mode == COOL) {
        strip.setPixelColor(0, PixelColorBlue);
        strip.show();
    } else if (mode == OFF) {
        strip.setPixelColor(0, PixelColorGold);
        strip.show();
    } else if (mode == HEAT) {
        strip.setPixelColor(0, PixelColorOrange);
        strip.show();
    } else if (mode == REDALERT) {
        strip.setPixelColor(0, PixelColorRed);
        strip.show();
    } else {
        strip.setPixelColor(0, PixelColorGold);
        strip.show();
    }
    delay(1000);
}

int setModeFromString(String inputString) {
    if (inputString == "Cool") {
        mode = COOL;
        return 0;
    } else if (inputString == "Off" ) {
        mode = OFF;
        return 1;
    } else if (inputString == "Heat") {
        mode = HEAT;
        return 2;
    } else if (inputString == "REDALERT") {
        mode = REDALERT;
        delay(2000);
        Particle.publish("djoCloudRedAlert", "Too hot, please add water!");
        return 3;
    } else {
        return -1; //If we get here return a Sentinel Value. -1 is common for errors.
    }
}
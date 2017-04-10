
#include "colour.h"
#include "FastLED.h"

#define pp(e) do { Serial.print(#e " = "); Serial.println(e); } while (0)

#define DATA_PIN 14
#define ROWS 8
#define COLUMNS 2

#define NUM_LEDS ROWS*COLUMNS
#define MASTER_BRIGHTNESS
colour_t leds[NUM_LEDS];
colour_matrix_t matrix;

const int knockSensor1 = A8;
const int knockSensor2 = A9;
const int knockSensor3 = A10;
const int knockSensor4 = A11;
const int knockSensor5 = A12;
const int knockSensor6 = A13;
const int knockSensor7 = A14;
const int knockSensor8 = A15;// the piezo is connected to analog pin 0



const int threshold=20;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int  sensorReading1 = 0;
int  sensorReading2 = 0;
int  sensorReading3 = 0;
int  sensorReading4 = 0;
int  sensorReading5 = 0;
int  sensorReading6 = 0;
int  sensorReading7 = 0;
int  sensorReading8 = 0;

void setup() { // declare the ledPin as as OUTPUT
  Serial.begin(9600);       // use the serial port
  matrix = colour_matrix_new(COLUMNS, ROWS, leds);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>((CRGB*)leds, NUM_LEDS);
  FastLED.setBrightness(255); 
  reset_led();
}

void reset_led (){
  for( int i=0; i<NUM_LEDS;++i){
    leds[i]= colour_rgb(0,255,0);
  }
  FastLED.setBrightness(255);
  FastLED.show();
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading1 = analogRead(knockSensor1);
  sensorReading2 = analogRead(knockSensor2);
  sensorReading3 = analogRead(knockSensor3);
  sensorReading4 = analogRead(knockSensor4);
  sensorReading5 = analogRead(knockSensor5);
  sensorReading6 = analogRead(knockSensor6);
  sensorReading7 = analogRead(knockSensor7);
  sensorReading8 = analogRead(knockSensor8);

  // if the sensor reading is greater than the threshold:
  if (sensorReading1 >= threshold) {
    Serial.println("Knock0!");
    set_row(matrix,0,colour_rgb(0,0,255)); 
    FastLED.setBrightness(255); 
    FastLED.show();
    delay(50);
    }

   if (sensorReading2 >= threshold) {
    Serial.println("Knock1!");
    set_row(matrix,1,colour_rgb(0,0,255)); 
    FastLED.setBrightness(255); 
    FastLED.show();
    delay(50);
    }
      
 if (sensorReading3 >=threshold){
    Serial.println("Knock2!");
    set_row(matrix,2,colour_rgb(0,0,255));
    FastLED.setBrightness(255); 
    FastLED.show();
    delay(50);
    }

  if (sensorReading4 >=threshold){
    Serial.println("Knock3!");
    set_row(matrix,3,colour_rgb(0,0,255));
    FastLED.setBrightness(255); 
    FastLED.show();
    delay(50);
    }

  if (sensorReading5 >=threshold){
    Serial.println("Knock4!");
    set_row(matrix,4,colour_rgb(0,0,255));
    FastLED.setBrightness(255); 
    FastLED.show();
    delay(50);
    }

  if (sensorReading6 >=threshold){
    Serial.println("Knock5!");
    set_row(matrix,5,colour_rgb(0,0,255));
    FastLED.setBrightness(255); 
    FastLED.show();
    delay(50);
    }

  if (sensorReading7 >=threshold){
    Serial.println("Knock6!");
    set_row(matrix,6,colour_rgb(0,0,255));
    FastLED.setBrightness(255); 
    FastLED.show();
    delay(50);
    }

  if (sensorReading8 >=threshold){
    Serial.println("Knock7!");
    set_row(matrix,7,colour_rgb(0,0,255));
    FastLED.setBrightness(255); 
    FastLED.show();
    delay(50);
    }
    reset_led();
}

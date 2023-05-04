// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 52 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 1000 // Time (in milliseconds) to pause between pixels
#define BRIGHTNESS 25 // Values: 0 - 255
const int GI[24] = {1,2,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};

// COLORS
uint32_t red = pixels.Color(255, 0, 0);
uint32_t green = pixels.Color(0, 255, 0);
uint32_t blue = pixels.Color(0, 0, 255);
uint32_t magenta = pixels.Color(255, 0, 255);
uint32_t cyan = pixels.Color(0, 255, 255);
uint32_t yellow = pixels.Color(255, 255, 0);
uint32_t white = pixels.Color(255, 255, 255);
uint32_t orange = pixels.Color(245, 132, 66);
uint32_t purple = pixels.Color(188, 66, 245);
uint32_t pink = pixels.Color(242, 94, 218);
uint32_t teal = pixels.Color(94, 242, 195);

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
    clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.
  pixels.setBrightness(BRIGHTNESS);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show(); // Set all pixel colors to 'off'
  //lightGI(red);
  lightK(green);
  // lightI(blue);
  // lightS1(magenta);
  // lightS2(cyan);
  // lightHS(yellow);
  // lightBIP(white);
  // lightSA(orange);
  // lightTilt(purple);
  // lightGO(pink);
  // lightMatch(teal);
}


void loop() {
  
  //raceLights();
  //lightSingle(51);
  //lightAll(yellow);
}

void lightGI(uint32_t color) {
  for (int i = 0; i < sizeof(GI); i++) {
    pixels.setPixelColor(GI[i], color);
    pixels.show();
  }
}

void lightAll(uint32_t color) {
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(i, color);
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
}

void lightK(uint32_t color) {
  int kLeds[6] = {2,3,4,5,6,7};

  // pixels.setPixelColor(2, color);
  // pixels.setPixelColor(3, color);
  // pixels.setPixelColor(4, color);
  // pixels.setPixelColor(5, color);
  // pixels.setPixelColor(6, color);
  // pixels.setPixelColor(7, color);
Serial.println("HELLO");
  for (int i = kLeds[0]; i < sizeof(kLeds); i++) {
    Serial.println(i);
    pixels.setPixelColor(kLeds[i], color);
    pixels.show();
  }
}

void lightI(uint32_t color) {
  int leds[3] = {8,9,10};

  // pixels.setPixelColor(8, color);
  // pixels.setPixelColor(9, color);
  // pixels.setPixelColor(10, color);

  for (int i = 0; i < sizeof(leds); i++) {
    pixels.setPixelColor(leds[i], color);
    pixels.show();
  }
}

void lightS1(uint32_t color) {
  int leds[4] = {11,12,13,14};
  pixels.setPixelColor(11, color);
  pixels.setPixelColor(12, color);
  pixels.setPixelColor(13, color);
  pixels.setPixelColor(14, color);

  // for (int i = 0; i < sizeof(leds); i++) {
  //   pixels.setPixelColor(leds[i], color);
     pixels.show();
  // }
}

void lightS2(uint32_t color) {
  int leds[4] = {15,16,17,18};
  pixels.setPixelColor(15, color);
  pixels.setPixelColor(16, color);
  pixels.setPixelColor(17, color);
  pixels.setPixelColor(18, color);

  // for (int i = 0; i < sizeof(leds); i++) {
  //   pixels.setPixelColor(leds[i], color);
     pixels.show();
  // }
}

// "High Score"
void lightHS(uint32_t color) {
  int leds[2] = {19,20};
  pixels.setPixelColor(19, color);
  pixels.setPixelColor(20, color);

  // for (int i = 0; i < sizeof(leds); i++) {
  //   pixels.setPixelColor(leds[i], color);
     pixels.show();
  // }
}

// "Ball In Play"
void lightBIP(uint32_t color) {
  int leds[2] = {21,22};
  pixels.setPixelColor(21, color);
  pixels.setPixelColor(22, color);

  // for (int i = 0; i < sizeof(leds); i++) {
  //   pixels.setPixelColor(leds[i], color);
     pixels.show();
  // }
}

// "Shoot Again"
void lightSA(uint32_t color) {
  int leds[2] = {45,46};
  pixels.setPixelColor(45, color);
  pixels.setPixelColor(46, color);

  // for (int i = 0; i < sizeof(leds); i++) {
  //   pixels.setPixelColor(leds[i], color);
     pixels.show();
  // }
}

void lightTilt(uint32_t color) {
  int leds[2] = {47,48};
  pixels.setPixelColor(47, color);
  pixels.setPixelColor(48, color);

  // for (int i = 0; i < sizeof(leds); i++) {
  //   pixels.setPixelColor(leds[i], color);
     pixels.show();
  // }
}

// "Game Over"
void lightGO(uint32_t color) {
  int leds[2] = {49,50};
  pixels.setPixelColor(49, color);
  pixels.setPixelColor(50, color);

  // for (int i = 0; i < sizeof(leds); i++) {
  //   pixels.setPixelColor(leds[i], color);
     pixels.show();
  // }
}

void lightMatch(uint32_t color) {
  int leds[3] = {51};
  pixels.setPixelColor(51, color);

  // for (int i = 0; i < sizeof(leds); i++) {
  //   pixels.setPixelColor(leds[i], color);
     pixels.show();
  // }
}

void raceLights(uint32_t color) {
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(255, 255, 255));

    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop  
  }
}

void lightSingle(int n) {
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.setPixelColor(n, pixels.Color(255,255,255));
  pixels.show();
  delay(DELAYVAL);  
}

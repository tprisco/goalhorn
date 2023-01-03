
#include <DFRobotDFPlayerMini.h>

#include <DFRobotDFPlayerMini.h>
#include <FastLED.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
SoftwareSerial mySoftwareSerial(6, 5);
#define DATA_PIN 2
#define NUM_LEDS    300
#define BRIGHTNESS  60
#define CHIPSET    WS2812B
#define COLOR_ORDER GRB
#define VOLTS 5
#define MAX_AMPS 500
CRGB leds[NUM_LEDS];
int val = 0;
int val2=0;
int val3 = 0;
int val4 = 0;
int count = 0;
int runTime = 0;
int finishTime = 0;
int relay = 3;
int  startTime = 0;
DFRobotDFPlayerMini myDFPlayer;
int patternCounter = 0;



void setup() {
  Serial.begin(9600);
 
  Serial.print("CONNECTED");
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(VOLTS, MAX_AMPS);
  FastLED.clear();
  FastLED.show();

 
  pinMode(9, INPUT);
  pinMode(relay, OUTPUT);

  
  myDFPlayer.begin(mySoftwareSerial);
   mySoftwareSerial.begin(9600);
  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(17);  //Set volume value. From 0 to 30

}
  



void loop() {

 
     val = digitalRead(9);
  if (val == HIGH)
  {
    
    myDFPlayer.play(1);  //Play the first mp3
    Serial.print("INPUT FOUND");

    digitalWrite(relay, HIGH);


    RunningLights(0xff, 0, 0, 1);

    digitalWrite(relay, LOW );
    colorWipe(0, 0, 50, 6);
    colorWipe(0xFF, 0x5F, 0x03, 6);
    colorWipe(0, 0, 50, 6);
    setAll(0, 0, 50);
    delay(830);
    setAll(0xFF, 0x5F, 0x03);
    delay(830);
    setAll(0, 0, 50);
    delay(830);
    setAll(0xFF, 0x5F, 0x03);
    delay(830);
   setAll(0, 0, 50);
    delay(830);
     setAll(0xFF, 0x5F, 0x03);
    delay(830);
     setAll(0, 0, 50);
     delay(830);
    setAll(0, 0, 0);
    delay(6140);
    setAll(0, 0, 0);
    setAll(255, 255, 255);
    delay(205);
    setAll(0, 0, 0);
    delay(205);
    setAll(255, 255, 255);
    delay(205);
    setAll(0, 0, 0);
    delay(205);
    setAll(255, 255, 255);
    delay(205);
    setAll(0, 0, 0);
    delay(205);
    setAll(255, 255, 255);
    delay(205);
    setAll(0, 0, 0);
    delay(205);
    setAll(255, 255, 255);
    delay(205);
    setAll(0, 0, 0);
    delay(205);
    setAll(255, 255, 255);
    delay(205);
    setAll(0, 0, 0);
    delay(205);
    setAll(255, 255, 255);
    delay(205);
    setAll(0, 0, 0);
    delay(205);
    setAll(255, 255, 255);
    setAll(0, 0, 0);
  }
  val2 = digitalRead(10);
if (val2 == HIGH)
{
   digitalWrite(relay, HIGH);
   myDFPlayer.volume(10);
    myDFPlayer.play(3);
      colorWipe(0, 0, 50, 6);
    colorWipe(0xFF, 0x5F, 0x03, 6);
    digitalWrite (relay, LOW);
    colorWipe(0, 0, 50, 6);
      colorWipe(0, 0, 50, 6);
    colorWipe(0xFF, 0x5F, 0x03, 6);
    colorWipe(0, 0, 50, 6);
}
val3 = digitalRead(11);
if (val3 == HIGH)
{
  myDFPlayer.volume(15);
   myDFPlayer.play(2);

   }
  
  
}
void RunningLights(byte red, byte green, byte blue, int WaveDelay) {
  int Position = 0;

  for (int j = 0; j < 180; j++)
  {
    Position++; // = 0; //Position + Rate;
    for (int i = 0; i < 300; i++) {
      // sine wave, 3 offset waves make a rainbow!
      //float level = sin(i+Position) * 127 + 128;
      //setPixel(i,level,0,0);
      //float level = sin(i+Position) * 127 + 128;
      setPixel(i, ((sin(i + Position) * 127 + 128) / 255)*red,
               ((sin(i + Position) * 127 + 128) / 255)*green,
               ((sin(i + Position) * 127 + 128) / 255)*blue);
    }

    showStrip();

  }
  FastLED.clear();

}
void showStrip() {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.show();
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  FastLED.show();
#endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}

void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  FastLED.show();
}
void colorWipe(byte red, byte green, byte blue, int SpeedDelay) {
  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    setPixel(i, red, green, blue);
    showStrip();
    delay(SpeedDelay);
  }
}

void FadeInOut(byte red, byte green, byte blue) {
  float r, g, b;

  for (int k = 0; k < 256; k = k + 1) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    setAll(r, g, b);
    showStrip();
  }

  for (int k = 255; k >= 0; k = k - 2) {
    r = (k / 256.0) * red;
    g = (k / 256.0) * green;
    b = (k / 256.0) * blue;
    setAll(r, g, b);
    showStrip();
  }
}
void Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause) {
  for (int j = 0; j < StrobeCount; j++) {
    setAll(red, green, blue);
    showStrip();
    delay(FlashDelay);
    setAll(0, 0, 0);
    showStrip();
    delay(FlashDelay);
  }

  delay(EndPause);
}

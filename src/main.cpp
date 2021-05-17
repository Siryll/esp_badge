#include <FastLED.h>

#define LED_PIN     15
#define COLOR_ORDER GRB
#define CHIPSET     WS2812
#define NUM_LEDS    240

#define BRIGHTNESS  50
#define FRAMES_PER_SECOND 60

long previousTime = 0;
int count = 0;
int starttime = 0;
int endtime = 0;
int loopcount = 0;
// Params for width and height
const uint8_t kMatrixWidth = 16;
const uint8_t kMatrixHeight = 16;

#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds[ NUM_LEDS ];
#define LAST_VISIBLE_LED 239
uint8_t XY (uint8_t x, uint8_t y) {
  // any out of bounds address maps to the first hidden pixel
  if ( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
    return (LAST_VISIBLE_LED + 1);
  }

  const uint8_t XYTable[] = {
   245, 244, 243,   9,   8,   7,   6,   5,   4,   3,   2,   1,   0, 242, 241, 240,
   246,  10,  11,  12,  13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23, 247,
    39,  38,  37,  36,  35,  34,  33,  32,  31,  30,  29,  28,  27,  26,  25,  24,
    40,  41,  42,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,  54,  55,
    71,  70,  69,  68,  67,  66,  65,  64,  63,  62,  61,  60,  59,  58,  57,  56,
    72,  73,  74,  75,  76,  77,  78,  79,  80,  81,  82,  83,  84,  85,  86,  87,
   103, 102, 101, 100,  99,  98,  97,  96,  95,  94,  93,  92,  91,  90,  89,  88,
   104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
   135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120,
   136, 137, 138, 139, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151,
   167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152,
   168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 180, 181, 182, 183,
   199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184,
   248, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 249,
   251, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 250,
   252, 253, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239, 254, 255
  };

  uint8_t i = (y * kMatrixWidth) + x;
  uint8_t j = XYTable[i];
  return j;
}

void MatrixMatrix(){
  //Update matrix every 75ms
   if(millis() - previousTime >= 75) {
    // Move bright spots downward
    for (int row = kMatrixHeight - 1; row >= 0; row--) {
      for (int col = 0; col < kMatrixWidth; col++) {
        if (leds[XY(col, row)] == CRGB(175,255,175)) {
          leds[XY(col, row)] = CRGB(27,200,39); // create trail
          if (row < kMatrixHeight - 1) leds[XY(col, row + 1)] = CRGB(175,255,175);
        }
      }
    }
    // Fade all leds
    for(int i = 0; i < NUM_LEDS; i++) {
      if (leds[i].g != 255) leds[i].nscale8(192); // only fade trail
    }
    // Spawn new falling spots
    if (random8(2) == 0) // lower number == more frequent spawns
    {
      int8_t spawnX = random8(kMatrixWidth);
      leds[XY(spawnX, 0)] = CRGB(175,255,175 );
    }
    //Show Sprite
    FastLED.show();
    //Update timer
    previousTime = millis();
  }
}
void NumberL0(){
  leds[XY(3, 9)] = CRGB(175,255,175);
  leds[XY(4, 9)] = CRGB(175,255,175);
  leds[XY(5, 9)] = CRGB(175,255,175);
  leds[XY(2, 10)] = CRGB(175,255,175);
  leds[XY(6, 10)] = CRGB(175,255,175);
  leds[XY(2, 11)] = CRGB(175,255,175);
  leds[XY(5, 11)] = CRGB(175,255,175);
  leds[XY(6, 11)] = CRGB(175,255,175);
  leds[XY(2, 12)] = CRGB(175,255,175);
  leds[XY(4, 12)] = CRGB(175,255,175);
  leds[XY(6, 12)] = CRGB(175,255,175);
  leds[XY(2, 13)] = CRGB(175,255,175);
  leds[XY(3, 13)] = CRGB(175,255,175);
  leds[XY(6, 13)] = CRGB(175,255,175);
  leds[XY(2, 14)] = CRGB(175,255,175);
  leds[XY(6, 14)] = CRGB(175,255,175);
  leds[XY(3, 15)] = CRGB(175,255,175);
  leds[XY(4, 15)] = CRGB(175,255,175);
  leds[XY(5, 15)] = CRGB(175,255,175);
  
}
void NumberL1(){
  leds[XY(4, 9)] = CRGB(175,255,175);
  leds[XY(3, 10)] = CRGB(175,255,175);
  leds[XY(4, 10)] = CRGB(175,255,175);
  leds[XY(4, 11)] = CRGB(175,255,175);
  leds[XY(4, 12)] = CRGB(175,255,175);
  leds[XY(4, 13)] = CRGB(175,255,175);
  leds[XY(4, 14)] = CRGB(175,255,175);
  leds[XY(3, 15)] = CRGB(175,255,175);
  leds[XY(4, 15)] = CRGB(175,255,175);
  leds[XY(5, 15)] = CRGB(175,255,175);
}
void NumberL2(){
  leds[XY(3, 9)] = CRGB(175,255,175);
  leds[XY(4, 9)] = CRGB(175,255,175);
  leds[XY(5, 9)] = CRGB(175,255,175);
  leds[XY(2, 10)] = CRGB(175,255,175);
  leds[XY(6, 10)] = CRGB(175,255,175);
  leds[XY(6, 11)] = CRGB(175,255,175);
  leds[XY(4, 12)] = CRGB(175,255,175);
  leds[XY(5, 12)] = CRGB(175,255,175);
  leds[XY(3, 13)] = CRGB(175,255,175);
  leds[XY(2, 14)] = CRGB(175,255,175);
  leds[XY(2, 15)] = CRGB(175,255,175);
  leds[XY(3, 15)] = CRGB(175,255,175);
  leds[XY(4, 15)] = CRGB(175,255,175);
  leds[XY(5, 15)] = CRGB(175,255,175);
  leds[XY(6, 15)] = CRGB(175,255,175);
  
}
void NumberLT(){
  leds[XY(3, 9)] = CRGB(175,255,175);
  leds[XY(3, 10)] = CRGB(175,255,175);
  leds[XY(3, 11)] = CRGB(175,255,175);
  leds[XY(3, 12)] = CRGB(175,255,175);
  leds[XY(3, 13)] = CRGB(175,255,175);
  leds[XY(3, 14)] = CRGB(175,255,175);
  leds[XY(3, 15)] = CRGB(175,255,175);
  leds[XY(4, 15)] = CRGB(175,255,175);
  leds[XY(5, 15)] = CRGB(175,255,175);
  leds[XY(6, 15)] = CRGB(175,255,175);
  leds[XY(7, 15)] = CRGB(175,255,175);

  leds[XY(9, 9)] = CRGB(175,255,175);
  leds[XY(10, 9)] = CRGB(175,255,175);
  leds[XY(11, 9)] = CRGB(175,255,175);
  leds[XY(12, 9)] = CRGB(175,255,175);
  leds[XY(13, 9)] = CRGB(175,255,175);
  leds[XY(11, 10)] = CRGB(175,255,175);
  leds[XY(11, 11)] = CRGB(175,255,175);
  leds[XY(11, 12)] = CRGB(175,255,175);
  leds[XY(11, 13)] = CRGB(175,255,175);
  leds[XY(11, 14)] = CRGB(175,255,175);
  leds[XY(11, 15)] = CRGB(175,255,175);
  
}
void NumberR0(){
  leds[XY(10, 9)] = CRGB(175,255,175);
  leds[XY(11, 9)] = CRGB(175,255,175);
  leds[XY(12, 9)] = CRGB(175,255,175);
  leds[XY(9, 10)] = CRGB(175,255,175);
  leds[XY(13, 10)] = CRGB(175,255,175);
  leds[XY(9, 11)] = CRGB(175,255,175);
  leds[XY(12, 11)] = CRGB(175,255,175);
  leds[XY(13, 11)] = CRGB(175,255,175);
  leds[XY(9, 12)] = CRGB(175,255,175);
  leds[XY(11, 12)] = CRGB(175,255,175);
  leds[XY(13, 12)] = CRGB(175,255,175);
  leds[XY(9, 13)] = CRGB(175,255,175);
  leds[XY(10, 13)] = CRGB(175,255,175);
  leds[XY(13, 13)] = CRGB(175,255,175);
  leds[XY(9, 14)] = CRGB(175,255,175);
  leds[XY(13, 14)] = CRGB(175,255,175);
  leds[XY(10, 15)] = CRGB(175,255,175);
  leds[XY(11, 15)] = CRGB(175,255,175);
  leds[XY(12, 15)] = CRGB(175,255,175);
  
}
void NumberR1(){
  leds[XY(11, 9)] = CRGB(175,255,175);
  leds[XY(10, 10)] = CRGB(175,255,175);
  leds[XY(11, 10)] = CRGB(175,255,175);
  leds[XY(11, 11)] = CRGB(175,255,175);
  leds[XY(11, 12)] = CRGB(175,255,175);
  leds[XY(11, 13)] = CRGB(175,255,175);
  leds[XY(11, 14)] = CRGB(175,255,175);
  leds[XY(10, 15)] = CRGB(175,255,175);
  leds[XY(11, 15)] = CRGB(175,255,175);
  leds[XY(12, 15)] = CRGB(175,255,175);
}
void NumberR2(){
  leds[XY(10, 9)] = CRGB(175,255,175);
  leds[XY(11, 9)] = CRGB(175,255,175);
  leds[XY(12, 9)] = CRGB(175,255,175);
  
  leds[XY(9, 10)] = CRGB(175,255,175);
  leds[XY(13, 10)] = CRGB(175,255,175);
  
  leds[XY(13, 11)] = CRGB(175,255,175);
  
  leds[XY(11, 12)] = CRGB(175,255,175);
  leds[XY(12, 12)] = CRGB(175,255,175);
  
  leds[XY(10, 13)] = CRGB(175,255,175);

  leds[XY(9, 14)] = CRGB(175,255,175);

  leds[XY(9, 15)] = CRGB(175,255,175);
  leds[XY(10, 15)] = CRGB(175,255,175);
  leds[XY(11, 15)] = CRGB(175,255,175);
  leds[XY(12, 15)] = CRGB(175,255,175);
  leds[XY(13, 15)] = CRGB(175,255,175);
}
void NumberR3(){
  leds[XY(10, 9)] = CRGB(175,255,175);
  leds[XY(11, 9)] = CRGB(175,255,175);
  leds[XY(12, 9)] = CRGB(175,255,175);
  
  leds[XY(9, 10)] = CRGB(175,255,175);
  leds[XY(13, 10)] = CRGB(175,255,175);
  
  leds[XY(13, 11)] = CRGB(175,255,175);
  
  leds[XY(11, 12)] = CRGB(175,255,175);
  leds[XY(12, 12)] = CRGB(175,255,175);

  leds[XY(13, 13)] = CRGB(175,255,175);

  leds[XY(9, 14)] = CRGB(175,255,175);
  leds[XY(13, 14)] = CRGB(175,255,175);

  leds[XY(10, 15)] = CRGB(175,255,175);
  leds[XY(11, 15)] = CRGB(175,255,175);
  leds[XY(12, 15)] = CRGB(175,255,175);

  
}
void NumberR4(){
  leds[XY(12, 9)] = CRGB(175,255,175);

  leds[XY(12, 10)] = CRGB(175,255,175);
  leds[XY(11, 10)] = CRGB(175,255,175);

  leds[XY(12, 11)] = CRGB(175,255,175);
  leds[XY(10, 11)] = CRGB(175,255,175);

  leds[XY(12, 12)] = CRGB(175,255,175);
  leds[XY(9, 12)] = CRGB(175,255,175);

  leds[XY(12, 13)] = CRGB(175,255,175);
  leds[XY(9, 13)] = CRGB(175,255,175);
  leds[XY(10, 13)] = CRGB(175,255,175);
  leds[XY(11, 13)] = CRGB(175,255,175);
  leds[XY(13, 13)] = CRGB(175,255,175);

  leds[XY(12, 14)] = CRGB(175,255,175);

  leds[XY(12, 15)] = CRGB(175,255,175);
}
void NumberR5(){
    leds[XY(9, 9)] = CRGB(175,255,175);
    leds[XY(10, 9)] = CRGB(175,255,175);
    leds[XY(11, 9)] = CRGB(175,255,175);
    leds[XY(12, 9)] = CRGB(175,255,175);
    leds[XY(13, 9)] = CRGB(175,255,175);
    leds[XY(9, 10)] = CRGB(175,255,175);
    leds[XY(9, 11)] = CRGB(175,255,175);
    leds[XY(10, 11)] = CRGB(175,255,175);
    leds[XY(11, 11)] = CRGB(175,255,175);
    leds[XY(12, 11)] = CRGB(175,255,175);
    leds[XY(13, 12)] = CRGB(175,255,175);
    leds[XY(13, 13)] = CRGB(175,255,175);
    leds[XY(9, 14)] = CRGB(175,255,175);
    leds[XY(13, 14)] = CRGB(175,255,175);
    leds[XY(10, 15)] = CRGB(175,255,175);
    leds[XY(11, 15)] = CRGB(175,255,175);
    leds[XY(12, 15)] = CRGB(175,255,175);
}
void NumberR6(){

leds[XY(11, 9)] = CRGB(175,255,175);
leds[XY(12, 9)] = CRGB(175,255,175);

leds[XY(10, 10)] = CRGB(175,255,175);

leds[XY(9, 11)] = CRGB(175,255,175);

leds[XY(9, 12)] = CRGB(175,255,175);
leds[XY(10, 12)] = CRGB(175,255,175);
leds[XY(11, 12)] = CRGB(175,255,175);
leds[XY(12, 12)] = CRGB(175,255,175);

  leds[XY(9, 13)] = CRGB(175,255,175);
  leds[XY(13, 13)] = CRGB(175,255,175);
  leds[XY(9, 14)] = CRGB(175,255,175);
  leds[XY(13, 14)] = CRGB(175,255,175);
  leds[XY(10, 15)] = CRGB(175,255,175);
  leds[XY(11, 15)] = CRGB(175,255,175);
  leds[XY(12, 15)] = CRGB(175,255,175);
}
void NumberR7(){
  leds[XY(9, 9)] = CRGB(175,255,175);
  leds[XY(10, 9)] = CRGB(175,255,175);
  leds[XY(11, 9)] = CRGB(175,255,175);
  leds[XY(12, 9)] = CRGB(175,255,175);
  leds[XY(13, 9)] = CRGB(175,255,175);
  leds[XY(13, 10)] = CRGB(175,255,175);
  leds[XY(12, 11)] = CRGB(175,255,175);
  leds[XY(11, 12)] = CRGB(175,255,175);
  leds[XY(10, 13)] = CRGB(175,255,175);
  leds[XY(10, 14)] = CRGB(175,255,175);
  leds[XY(10, 15)] = CRGB(175,255,175);



  
}
void NumberR8(){
   leds[XY(10, 9)] = CRGB(175,255,175);
  leds[XY(11, 9)] = CRGB(175,255,175);
  leds[XY(12, 9)] = CRGB(175,255,175);
  
  leds[XY(9, 10)] = CRGB(175,255,175);
  leds[XY(13, 10)] = CRGB(175,255,175);

  leds[XY(9, 11)] = CRGB(175,255,175);
  leds[XY(13, 11)] = CRGB(175,255,175);

  leds[XY(10, 12)] = CRGB(175,255,175);
  leds[XY(11, 12)] = CRGB(175,255,175);
  leds[XY(12, 12)] = CRGB(175,255,175);

  leds[XY(9, 13)] = CRGB(175,255,175);
  leds[XY(13, 13)] = CRGB(175,255,175);

  leds[XY(9, 14)] = CRGB(175,255,175);
  leds[XY(13, 14)] = CRGB(175,255,175);

  leds[XY(10, 15)] = CRGB(175,255,175);
  leds[XY(11, 15)] = CRGB(175,255,175);
  leds[XY(12, 15)] = CRGB(175,255,175);
}
void NumberR9(){
  
}

void CyberEyes(){
  if(millis() - previousTime >= 75)
  {
    leds[XY(0, 2)] = CRGB(175,255,175);
    leds[XY(1, 2)] = CRGB(175,255,175);
    leds[XY(14, 2)] = CRGB(175,255,175);
    leds[XY(15, 2)] = CRGB(175,255,175);

    leds[XY(0, 3)] = CRGB(175,255,175);
    leds[XY(1, 3)] = CRGB(175,255,175);
    leds[XY(2, 3)] = CRGB(175,255,175);
    leds[XY(3, 3)] = CRGB(175,255,175);
    leds[XY(12, 3)] = CRGB(175,255,175);
    leds[XY(13, 3)] = CRGB(175,255,175);
    leds[XY(14, 3)] = CRGB(175,255,175);
    leds[XY(15, 3)] = CRGB(175,255,175);

    leds[XY(0, 4)] = CRGB(175,255,175);
    leds[XY(1, 4)] = CRGB(175,255,175);
    leds[XY(2, 4)] = CRGB(175,255,175);
    leds[XY(3, 4)] = CRGB(175,255,175);
    leds[XY(4, 4)] = CRGB(175,255,175);
    leds[XY(5, 4)] = CRGB(175,255,175);
    leds[XY(10, 4)] = CRGB(175,255,175);
    leds[XY(11, 4)] = CRGB(175,255,175);
    leds[XY(12, 4)] = CRGB(175,255,175);
    leds[XY(13, 4)] = CRGB(175,255,175);
    leds[XY(14, 4)] = CRGB(175,255,175);
    leds[XY(15, 4)] = CRGB(175,255,175);

    leds[XY(1, 5)] = CRGB(175,255,175);
    leds[XY(2, 5)] = CRGB(175,255,175);
    leds[XY(3, 5)] = CRGB(175,255,175);
    leds[XY(4, 5)] = CRGB(175,255,175);
    leds[XY(5, 5)] = CRGB(175,255,175);
    leds[XY(6, 5)] = CRGB(175,255,175);
    leds[XY(9, 5)] = CRGB(175,255,175);
    leds[XY(10, 5)] = CRGB(175,255,175);
    leds[XY(11, 5)] = CRGB(175,255,175);
    leds[XY(12, 5)] = CRGB(175,255,175);
    leds[XY(13, 5)] = CRGB(175,255,175);
    leds[XY(14, 5)] = CRGB(175,255,175);

    leds[XY(2, 6)] = CRGB(175,255,175);
    leds[XY(3, 6)] = CRGB(175,255,175);
    leds[XY(4, 6)] = CRGB(175,255,175);
    leds[XY(5, 6)] = CRGB(175,255,175);
    leds[XY(10, 6)] = CRGB(175,255,175);
    leds[XY(11, 6)] = CRGB(175,255,175);
    leds[XY(12, 6)] = CRGB(175,255,175);
    leds[XY(13, 6)] = CRGB(175,255,175);

    //Numbers start here

    NumberL0();
    NumberR0();
    
  
    FastLED.show();
    previousTime = millis();
  }
}

void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  FastLED.setBrightness( BRIGHTNESS );
}



void loop()
{
  starttime = millis();
  endtime = starttime;
  while((endtime - starttime) <=10000) // do this loop for up to 1000mS
  {
  CyberEyes();
  loopcount = loopcount+1;
  endtime = millis();
  }
  FastLED.clear();  // clear all pixel data
  FastLED.show();
  starttime = millis();
  endtime = starttime;
  while((endtime - starttime) <=10000) // do this loop for up to 1000mS
  {
  MatrixMatrix();
  loopcount = loopcount+1;
  endtime = millis();
  }
  FastLED.clear();  // clear all pixel data
  FastLED.show();
}

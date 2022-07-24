#include <Arduino.h>
#include <FastLED.h>




#define LED_PIN     2 
#define NUM_LEDS    36
#define BRIGHTNESS  50
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

void FillLEDsFromPaletteColors( uint8_t colorIndex);





#define UPDATES_PER_SECOND 100


CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;


void setup() {

  
    Serial.begin(9600);
    delay( 3000 ); // power-up safety delay
        
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    
    FastLED.setBrightness(  BRIGHTNESS );
    
    
}


void loop()
{



              currentPalette = RainbowColors_p;  
                 
              currentBlending = LINEARBLEND;
              static uint8_t startIndex = 0;
              startIndex = startIndex + 1; /* motion speed */
              FillLEDsFromPaletteColors( startIndex);
              FastLED.show();
              FastLED.delay(1000 / UPDATES_PER_SECOND);

            
  }   


///////////////////////////////////////////////////////////////////////////////////////////////////////
void set_color(int led_id[3],int R,int G,int B){
int i=0;
for(i=0;i<3;i++){
leds[led_id[i]-1] = CRGB (R,G,B);  
} 
}

//////////// PATTERNS  //////////////////////////////////////////////////////////////////////////////////




void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; ++i) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

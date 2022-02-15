/*
  This sketch is the same as the Font_Demo_1 example, except the fonts in this
  example are in a FLASH (program memory) array. This means that processors
  such as the STM32 series that are not supported by a SPIFFS library can use
  smooth (anti-aliased) fonts.
*/

/*
  There are four different methods of plotting anti-aliased fonts to the screen.

  This sketch uses method 1, using tft.print() and tft.println() calls.

  In some cases the sketch shows what can go wrong too, so read the comments!
  
  The font is rendered WITHOUT a background, but a background colour needs to be
  set so the anti-aliasing of the character is performed correctly. This is because
  characters are drawn one by one.
  
  This method is good for static text that does not change often because changing
  values may flicker. The text appears at the tft cursor coordinates.

  It is also possible to "print" text directly into a created sprite, for example using
  spr.println("Hello"); and then push the sprite to the screen. That method is not
  demonstrated in this sketch.
  
*/

//  A processing sketch to create new fonts can be found in the Tools folder of TFT_eSPI
//  https://github.com/Bodmer/TFT_eSPI/tree/master/Tools/Create_Smooth_Font/Create_font

//  This sketch uses font files created from the Noto family of fonts:
//  https://www.google.com/get/noto/

#include "NotoSansBold15.h"
#include "NotoSansBold36.h"



// The font names are arrays references, thus must NOT be in quotes ""
#define AA_FONT_SMALL NotoSansBold15
#define AA_FONT_LARGE NotoSansBold36




#include <SPI.h>
#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();


void setup(void) {

  Serial.begin(250000);

  tft.begin();

  tft.setRotation(1);
}


void loop() {

  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set the font colour AND the background colour
                                          // so the anti-aliasing works

  tft.setCursor(0,0); // Set cursor at top left of screen


  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // PART ONE
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  Serial.println("Loading font");

  tft.loadFont(AA_FONT_SMALL);    // Must load the font first
  tft.setTextWrap(true); // Wrap on width

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.println("Photo album on the counter, ");
  tft.print("your cheeks were turning ");
  tft.setTextColor(TFT_RED, TFT_BLACK); 
  tft.println("red"); 
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.println("you used to be a little kid with ");
  tft.println("glasses in a twin-sized bed, and"); 
  tft.println("your mother's telling stories ");
  tft.println("'bout you on the tee-ball team, "); 
  tft.println("you taught me 'bout your past, "); 
  tft.println("thinking your future was me ");

  delay(20000); //50.....9 *19 seconds

  // Get ready for the next demo while we have this font loaded
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0,0); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
//  tft.println("Wrong and right ways to");
//  tft.println("print changing values...");

  tft.unloadFont(); // Remove the font to recover memory used

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// PART TWO
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  Serial.println("Loading font");

  tft.loadFont(AA_FONT_SMALL);    // Must load the font first 
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.println("and you were tossing me the ");
  tft.print("car keys   "); 
  tft.loadFont(AA_FONT_LARGE);    // Must load the font first 
  tft.setTextColor(TFT_PINK, TFT_BLACK);
  tft.println("FUCK");
  tft.println("THE");
  tft.println("PATRIARCHY"); //14  *5 seconds


  delay(4000);

  // Get ready for the next demo while we have this font loaded
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0
  ); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK);


  tft.unloadFont(); // Remove the font to recover memory used

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// PART THREE
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  Serial.println("Loading font");

  tft.loadFont(AA_FONT_SMALL);    // Must load the font first
  tft.setTextWrap(true); // Wrap on width

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  
  tft.println("key chain on the ground, we ");
  tft.println("were always skipping town, ");
  tft.println("and I was  thinking on the ");
  tft.println("drive down, any time now, he's ");
  tft.println("gonna say it's love, you never ");
  tft.println("called it what it was, 'til we ");
  tft.println("were dead and gone and ");
  tft.println("buried, check the pulse"); //33 *19 SECONDS

 
  delay(20000);

  // Get ready for the next demo while we have this font loaded
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0,0); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
//  tft.println("Wrong and right ways to");
//  tft.println("print changing values...");

  tft.unloadFont(); // Remove the font to recover memory used

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// PART FOUR
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  Serial.println("Loading font");

  tft.loadFont(AA_FONT_SMALL);    // Must load the font first
  tft.setTextWrap(true); // Wrap on width

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.println("and come back swearing it's");
  tft.println("the same, after three months ");
  tft.println("in the grave, and then you ");
  tft.println("wondered where it went to as ");
  tft.println("I reached for you, but all I ");
  tft.println("felt was shame and you held");


  tft.setTextColor(TFT_SILVER, TFT_BLACK);
  tft.println("my           lifeless           frame"); //51 *18 SECS

  
 
  delay(19000);

  // Get ready for the next demo while we have this font loaded
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0,0); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
//  tft.println("Wrong and right ways to");
//  tft.println("print changing values...");

  tft.unloadFont(); // Remove the font to recover memory used



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// PART FIVE
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  Serial.println("Loading font");

  tft.loadFont(AA_FONT_SMALL);    // Must load the font first
  tft.setTextWrap(true); // Wrap on width

  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.println("All Too Well");
  tft.println("(10 Minute Version)");
  tft.println("(Taylor's Version)");
  tft.println("[Live Acoustic]");
  tft.println("Taylor Swift"); 

  
 
  delay(5000);

  // Get ready for the next demo while we have this font loaded
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0,0); // Set cursor at top left of screen
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
//  tft.println("Wrong and right ways to");
//  tft.println("print changing values...");

  tft.unloadFont(); // Remove the font to recover memory used


  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Large font
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//  tft.loadFont(AA_FONT_LARGE); // Load another different font
//
//  tft.fillScreen(TFT_BLACK);
//  
//  // Draw changing numbers - does not work unless a filled rectangle is drawn over the old text
////  for (int i = 0; i <= 20; i++)
////  {
////    tft.setCursor(50, 50);
////    tft.print("      "); // Overprinting old number with spaces DOES NOT WORK!
////    tft.setTextColor(TFT_GREEN, TFT_BLACK);
////    tft.setCursor(50, 50);
////    //tft.print(i / 10.0, 1);
////    tft.println("hello"); 
////
////    tft.fillRect (50, 90, 60, 40, TFT_BLACK); // Overprint with a filled rectangle
////    tft.setTextColor(TFT_GREEN, TFT_BLACK);
////    tft.setCursor(50, 90);
////    //tft.print(i / 10.0, 1);
////    tft.println("dsjhjdsjn"); 
////    
////    //delay (200);
////  }
//
//
//  delay(5000);

  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  // Large font text wrapping
  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

//  tft.fillScreen(TFT_BLACK);
//  
//  tft.setTextColor(TFT_YELLOW, TFT_BLACK); // Change the font colour and the background colour
//
//  tft.setCursor(0, 0); // Set cursor at top left of screen
//
//  tft.println("Large font!");
//
//  tft.setTextWrap(true); // Wrap on width
//  tft.setTextColor(TFT_CYAN, TFT_BLACK);
//  tft.println("Long lines wrap to the next line");
//
//  tft.setTextWrap(false, false); // Wrap on width and height switched off
//  tft.setTextColor(TFT_MAGENTA, TFT_BLACK);
//  tft.println("Unless text wrap is switched off");
//
//  tft.unloadFont(); // Remove the font to recover memory used
//
//  delay(8000);
}

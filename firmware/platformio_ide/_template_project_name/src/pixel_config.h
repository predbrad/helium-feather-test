/*
//==============================================================================
  Project:   Project Name
  Client:    Client Name

  Developer: Matt Starfield (matt.starfield@nextfab.com) | NextFab
  GitHub:    https://github.com/MattStarfield
//==============================================================================
  * Description:
    Define display scenes and supporting functions for NeoPixels
//==============================================================================
*/

#ifndef PIXEL_CONFIG_H
#define PIXEL_CONFIG_H
#include "Arduino.h"                    // includes all AVR & Arduino-specific definfitions (case sensitive file name on Linux)

#include "app_config.h"

#include "Adafruit_NeoPixel.h"          // v1.6.0 https://github.com/adafruit/Adafruit_NeoPixel

//#include "myBlinker

//==============================================================================
// == Pixel Configuration == //
//==============================================================================

  #define NUM_PIXELS                          1      // Total Number of addressable Pixels in a strip

// Define Pixel Addresses
  #define UI_PIXEL                            0
  //#define _PIXEL                            1
  //#define _PIXEL                            2
  //#define _PIXEL                            3
  //#define _PIXEL                            4
  //#define _PIXEL                            5
  //#define _PIXEL                            6
  //#define _PIXEL                            7


// 16-bit HSV Hue Value Names
//----------------------------------------------------------------------------
  // https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use#hsv-hue-saturation-value-colors-dot-dot-dot-17-41

  #define RED                                   0
  #define AMBER                                 7645
  #define YELLOW                                8737
  #define GREEN                                 21845

//==============================================================================
// == Pixel Scenes == //
//==============================================================================

  typedef enum pixelSceneEnum
  // * List of names of possible "scenes" (display sequences) that a NeoPixel can display for this application
  {
    PIX_NOT_SET,                   // default to catch uninitialized states

    PIX_OFF,
    PIX_WAITING,
    PIX_COUNTDOWN,
    PIX_READY,
    PIX_NOT_READY,
    PIX_ALERT,

    PIX_NUM_SCENES,

  }; // END enum


  // Declare Global Variables for Pixel Scenes
  //----------------------------------------------------------------------------
    //extern pixelSceneEnum uiPixelScene;


//==============================================================================
// == Function Prototypes == //
//==============================================================================



#endif  // END -- PIXEL_CONFIG_H

/*
//==============================================================================
  Developer: Matt Starfield (matt.starfield@nextfab.com) | NextFab
  GitHub:    https://github.com/MattStarfield
//==============================================================================
  * Description:
    Define settings, configurations, and behavior of various Device Operating Modes
//==============================================================================
*/

#ifndef DEVICE_MODE_H
#define DEVICE_MODE_H
#include "Arduino.h"                    // includes all AVR & Arduino-specific definfitions (case sensitive file name on Linux)

#include "app_config.h"

//==============================================================================
// == Device Operating Modes == //
//==============================================================================
  // *  Selection of Operation States that allow the device to be put into various
  //    operating modes for development, testing, debug, burn-in, setup / config, or production

  // *  Different from Debug Mode which controls print statements

  enum deviceModeEnum
  {
    DEV_MODE_NOT_SET,             // default to catch uninitialized states

    NORMAL_MODE,
    FIRST_RUN_MODE,
    SETUP_MODE,
    DEVELOPMENT_MODE,             // spell it out so not confused with "DEV_MODE"
    TEST_MODE,
    BURN_IN_MODE,

    DEV_MODE_NUM_STATES,

  }; // END deviceModeEnum

  // Enum Strings stored in PROGMEM
  //----------------------------------------------------------------------------
    // const char descriptions [NUMBER_OF_ELEMENTS] [MAX_SIZE] PROGMEM = {
    // http://www.gammon.com.au/forum/?id=12615
    const char deviceModeString [DEV_MODE_NUM_STATES] [ENUM_STRING_BUFFER_SIZE] PROGMEM =
    {
      {"DEV_MODE_NOT_SET"},                    // default to catch uninitialized states

      {"NORMAL_MODE"},
      {"FIRST_RUN_MODE"},
      {"SETUP_MODE"},
      {"DEVELOPMENT_MODE"},
      {"TEST_MODE"},
      {"BURN_IN_MODE"},

    };


//==============================================================================
// == Function Prototypes == //
//==============================================================================



#endif  // END -- DEVICE_MODE_H

/*
//==============================================================================
  Project:   CHOP Lab Instrumentation
  Client:    Steven Zderic

  Developer: Matt Starfield (matt.starfield@nextfab.com) | NextFab
  GitHub:    https://github.com/MattStarfield
//==============================================================================
  * Description:
    Define configuration and customizable settings for application firmware in a
    single, easily editable location.
//==============================================================================
*/

#ifndef APP_CONFIG_H
#define APP_CONFIG_H
#include "Arduino.h"                    // includes all AVR & Arduino-specific definfitions (case sensitive file name on Linux)


//==============================================================================
// == App Info == //
//==============================================================================

  #define FIRMWARE_VERSION                  "v0.0.1"
  #define FIRMWARE_NAME                     "Firmware_Name"

//==============================================================================
// == App Settings == //
//==============================================================================

  // Device Operating Mode
  //----------------------------------------------------------------------------
    /*
      DEVICE_MODE_NOT_SET
      NORMAL_MODE
      FIRST_RUN_MODE
      SETUP_MODE
      DEVELOPMENT_MODE
      TEST_MODE
    */
    #define DEVICE_MODE_DEFAULT               DEVELOPMENT_MODE    // options listed in device_mode_config.h
    //#define DEVICE_MODE_DEFAULT               NORMAL_MODE    // options listed in device_mode_config.h

  // Debug Mode
  //----------------------------------------------------------------------------
    /*
      DBG_NONE - no debug output is shown
      DBG_ERROR - critical errors
      DBG_WARNING - non-critical errors
      DBG_INFO - information
      DBG_DEBUG - more information
      DBG_VERBOSE - most information
    */
    #define DEBUG_LEVEL_DEFAULT                DBG_NONE       // sets the debugLevel prior to FSM_SYS_INIT_DEV
    // Use deviceMode definitions in FSM_SYS_INIT_DEV to set debugLevel for each deviceMode


  // Session Settings
  //----------------------------------------------------------------------------
    #define SESSION_COUNTDOWN_TIME            5     // seconds
    #define SESSION_REPEATS_NUM_OF_OPTIONS    2     // number of options in sessionRepeatsList[]

  // Sensor Settings
  //----------------------------------------------------------------------------

    #define PRESSURE_NUM_SAMPLES              10     // number of Pressure Sensor readings to average over
    #define PRESSURE_MAX_VALUE_KPA            10.0   // kPa - maximum value of pressure sensor range
    #define PRESSURE_MAX_ERROR_KPA            0.5    // kPa - maximu error of pressure sensor reading

  // Actuator Settings
  //----------------------------------------------------------------------------
    #define FAN_PWM_DEFAULT                   255  // (0 - 255) default PWM duty cycle
    #define FAN_PWM_MAX                       255  // (0 - 255) Max PWM duty cycle allowed in software
    #define FAN_PWM_MIN                       70   // (0 - 255) Min PWM duty cycle allowed in software

  // Watchdog Timer Settings
  //----------------------------------------------------------------------------
    #define WATCHDOG_TIMER_MS                 2000 // (ms), watchdog will reboot system if it hangs for this long

//==============================================================================
// == Pin Configuration == //
//==============================================================================

  // Arduino Nano   https://upload.wikimedia.org/wikipedia/commons/e/e4/Arduino-nano-pinout.png
  //----------------------------------------------------------------------------

    #define PIN_SYS_LED                       13  // SPI-SCK; OB-LED //
    #define PIN_PIXELS                        12  // SPI-MISO   // Neopixel Data Output, used by pixel_config.h
    //#define PIN_                            11  // SPI-MOSI; PWM //
    #define PIN_BUZZER                        10  // PWM        //
    #define PIN_FADE_LED                       9  // PWM        //
    //#define PIN_                             8  //            // not on Feather
    //#define PIN_                             7  //            // not on Feather
    #define PIN_FAN_PWM                        6  // PWM        //
    //#define PIN_                             5  // PWM        //
    //#define PIN_                             4  //            // not on Feather
    #define PIN_FAN_TACH                       3  // INT1; PWM  //
    #define PIN_UI_BUTTON                      2  // INT0       //
    //#define PIN_                             0  // RX0 (avoid use) //
    //#define PIN_                             1  // TX1        //

    #define PIN_PRESSURE_SENSOR               A0  // Analog In  //
    #define PIN_POT                           A1  // Analog In  //
    //#define PIN_                            A2  // Analog In  //
    //#define PIN_                            A3  // Analog In  //
    //#define PIN_                            A4  // I2C-SDA; A-In //
    //#define PIN_                            A5  // I2C-SCL; A-In //
    //#define PIN_                            A6  // NANO Analog In ONLY //
    //#define PIN_                            A7  // NANO Analog In ONLY //


//==============================================================================
// == Peripheral Settings == //
//==============================================================================

  // Serial Settings
  //----------------------------------------------------------------------------
    #define SERIAL_BAUD_RATE                  115200    // (bps); e.g. 9600, 19200, 57600, 115200

  // EasyButton Settings
  //----------------------------------------------------------------------------
    #define BTN_HOLD_DURATION_MS              3000    // duration for onPressedFor
    #define BTN_SEQ_NUM_CLICKS                2       // number of clicks for onSequence
    #define BTN_SEQ_TIMEOUT_MS                (BTN_SEQ_NUM_CLICKS*200)    // timeout window for onSequence

  // EasyLed Settings
  //----------------------------------------------------------------------------

    //          led.blink(    onFor_ms, offFor_ms,  cycles,  pauseFor_ms,  numOfSequeces,  onFinished_cb() );
    #define LED_HEARTBEAT     30,       200,        2,        1000,         0,              NULL
    #define LED_ATTENTION     50,       100,        5,        500,          0,              NULL
    #define LED_ERROR         500,      500,        2,        0,            0,              NULL
    #define LED_ACTIVITY      100,      100,        1,        10,           1,              NULL

  // EasyBuzzer Settings
  //----------------------------------------------------------------------------
    // usable frequency range: ~500 to ~12,000 Hz,
    // EasyBuzzer.beep(      frequency, onFor_ms, offFor_ms,  cycles, pauseFor_ms, numOfSequeces, onFinished_cb() );
    #define BEEP_OK           4000,     50,       0,          1,      10,           1,             NULL
    #define BEEP_ATTENTION    9000,     50,       100,        4,      10,           1,             NULL
    #define BEEP_CHIRP        10000,    15,       0,          1,      10,           1,             NULL
    #define BEEP_ERROR        500,      500,      500,        2,      1000,         1,             NULL
    #define BEEP_WARNING
    #define BEEP_HEARTBEAT

  // NeoPixel Settings
  //----------------------------------------------------------------------------
    // defined in pixel_config.h

  // Potentiometer Settings
  //----------------------------------------------------------------------------
    #define POT_TOLERANCE                  10
    #define POT_NUM_SAMPLES                5

//==============================================================================
// == Other Macros == //
//==============================================================================

  #define ENUM_STRING_BUFFER_SIZE           64    // length of longest enum string; used for PROGMEM print

  #define LOOP_TIME_NUM_SAMPLES             10

  #define WAIT_MESSAGE_REFRESH_INTERVAL_MS  5000
  #define WAIT_MESSAGE_PRINT_PERIODICALLY   false // determines if FSM_SYS_WAIT message prints once or refreshes periodically

  #define CLI_INPUT_DESIGNATOR              "\n\r<< "
  #define CLI_OUTPUT_DESIGNATOR             "\n\r>> "

  // LED & Pixel PWM Brightness values
  //----------------------------------------------------------------------------
    #define BRI_MAX                           255    // (0 - 255) Max allowable brightness
    #define BRI_DEFAULT                       200
    #define BRI_MIN                           50     // (0 - 255) Min visible brightness


  // Active Low Logic
  //----------------------------------------------------------------------------
    #define AL_DISABLE                        true
    #define AL_ENABLE                         false


    // Data Types Value Ranges
    //------------
    //#define INT16_MAX                         SHRT_MAX   // int           // 2 bytes //  32,768
    //#define INT16_MIN                         SHRT_MIN   // int           // 2 bytes // -32,768

    //#define UINT16_MAX                        USHRT_MAX  // unsigned int  // 2 bytes //  65,535
    //#define UINT16_MIN                        0          // unsigned int  // 2 bytes //  0

    //#define INT32_MAX                         INT_MAX    // long          // 4 bytes //  2,147,483,647
    //#define INT32_MIN                         INT_MIN    // long          // 4 bytes // -2,147,483,648

    //#define UINT32_MAX                        UINT_MAX   // unsigned long // 4 bytes // 4294967295
    //#define UINT32_MIN                        0          // unsigned long // 4 bytes // 0

    //#define FLOAT_MAX                         FLT_MAX    // float         // 4 bytes  //  3.4028235E+38
    //#define FLOAT_MIN                         FLT_MIN    // float         // 4 bytes  // -3.4028235E+38

//==============================================================================
// == Debug Print Helper Functions == //
//==============================================================================

  // Must be #define inline function to preserve intended use of function name and line number keywords
  #define DEBUG_PRINT_FUNCTION_LINE Debug.print(DBG_DEBUG, "\n\r"); Debug.print(DBG_DEBUG, "[D] [%s(): L#%d]", __func__, __LINE__)

  // Enum Strings stored in PROGMEM
  //----------------------------------------------------------------------------
    // const char stringName [NUMBER_OF_ELEMENTS] [MAX_SIZE] PROGMEM = {
    // http://www.gammon.com.au/forum/?id=12615
    const char debugLevelString [6] [ENUM_STRING_BUFFER_SIZE] PROGMEM =
    {
      {"DBG_NONE"},
      {"DBG_ERROR"},
      {"DBG_WARNING"},
      {"DBG_INFO"},
      {"DBG_DEBUG"},
      {"DBG_VERBOSE"},
    };  // END -- debugLevelString[][]

#endif  // END -- APP_CONFIG_H

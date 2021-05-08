/*
//==============================================================================
  Developer: Matt Starfield (matt.starfield@nextfab.com) | NextFab
  GitHub:    https://github.com/MattStarfield
//==============================================================================
  * Description:
    Define states and supporting functions for the application's finite state machine
//==============================================================================
*/

#ifndef FSM_CONFIG_H
#define FSM_CONFIG_H
#include "Arduino.h"                    // includes all AVR & Arduino-specific definfitions (case sensitive file name on Linux)

#include "app_config.h"

//==============================================================================
// == Finite State Machine States == //
//==============================================================================
  // * Non-ordered, Non-heirarchical state list
  //  * INIT: run once, prepare for RUN state, transition to RUN state immediately
  //  * RUN:   run continuously until event triggers state transition to EXIT state
  //  * EXIT:  run once, execute tasks on completion of RUN, determine which state to transition to next
  typedef enum fsmEnum
  {
    FSM_NOT_SET,                     // KEEP FIRST - default to catch uninitialized states

    FSM_SYS_INIT_DEV,                 // device start up sequence (can use to "warm reboot")

    FSM_SYS_WAIT,                         // idle here when app needs event to proceed

    FSM_SYS_INIT_APP,                     // print info based on deviceMode

    FSM_SES_INIT,                 // initialize global vars related to SESSION

    // Various "Stages" can be nested within a "Session"
      FSM_STG_INIT_STAGE1,                 // capture stageStartTimestamp, set output/actuator states
      FSM_STG_RUN_STAGE1,                   // perform stage duties continuously until event triggers transition to EXIT
      FSM_STG_EXIT_STAGE1,                  // reset output/actuator states

      //add more stages here...

    FSM_SES_COUNT_CHECK,                // used to repeat stage list a set number of times (burn-in, test mode)

    FSM_SES_INIT_CLOSE,            // calculate sessionRuntime, set output/actuator states
    FSM_SES_RUN_CLOSE,              // idle here when app needs an event trigger to leave "completed" state
    FSM_SES_EXIT_CLOSE,             // transition back to FSM_SES_INIT

    // Alerts trigger warning events, but do not force the App to stop operation
    FSM_SYS_INIT_ALERT,                // stop / clear all outputs / actuators, log alert info
    FSM_SYS_RUN_ALERT,                  // continuously run alert routine until acknowledged or handled
    FSM_SYS_EXIT_ALERT,                 // clear alert outputs / actuators, transition to FSM_SES_INIT

    // Errors require the App to stop normal operation until resolved
    FSM_SYS_INIT_ERROR,                // stop / clear all outputs / actuators, log error info
    FSM_SYS_RUN_ERROR,                  // continuously run error routine until acknowledged or handled
    FSM_SYS_EXIT_ERROR,                 // clear error outputs / actuators, transition to FSM_SES_INIT

    FSM_NUM_STATES,                       // KEEP LAST - upper bound of valid FSM_STATES

  }; // END fsmEnum


  // Declare Global FSM state variables
  //----------------------------------------------------------------------------
    // extern keyword allows global vars to be accessible to all other program files
    // declare in .h, but MUST define / initialize in .cpp or .ino

    //extern fsmEnum fsmState;             // hold the current fsm state used by switch(case) in loop()
    //extern fsmEnum fsmNextState;         // hold the next fsm state (optional)
    //extern fsmEnum fsmPriorState;        // store the prior fsm state when fsmNextState is used (optional)


  // Enum Strings stored in PROGMEM
  //----------------------------------------------------------------------------
    // const char descriptions [NUMBER_OF_ELEMENTS] [MAX_SIZE] PROGMEM = {
    // http://www.gammon.com.au/forum/?id=12615
    const char fsmStateString [FSM_NUM_STATES] [ENUM_STRING_BUFFER_SIZE] PROGMEM =
    {
      {"FSM_NOT_SET"},                    // default to catch uninitialized states

      {"FSM_SYS_INIT_DEV"},

      {"FSM_SYS_INIT_APP"},

      {"FSM_SYS_WAIT"},

      {"FSM_SES_INIT"},

        {"FSM_STG_INIT_STAGE1"},
        {"FSM_STG_RUN_STAGE1"},
        {"FSM_STG_EXIT_STAGE1"},

      {"FSM_SES_COUNT_CHECK"},

      {"FSM_SES_INIT_CLOSE"},
      {"FSM_SES_RUN_CLOSE"},
      {"FSM_SES_EXIT_CLOSE"},

      {"FSM_SYS_INIT_ALERT"},
      {"FSM_SYS_RUN_ALERT"},
      {"FSM_SYS_EXIT_ALERT"},

      {"FSM_SYS_INIT_ERROR"},
      {"FSM_SYS_RUN_ERROR"},
      {"FSM_SYS_EXIT_ERROR"},

    };  // END -- fsmStateString[][]


//==============================================================================
// == Exit Conditions == //
//==============================================================================

  typedef enum exitConditionEnum
  // * records the reason / condition that caused an FSM state to exit
  {
    EXIT_NOT_SET,          // default to catch uninitialized states

    EXIT_STG_TIMEOUT,

    EXIT_SES_TIMEOUT,
    EXIT_SES_ALERT_1,

    EXIT_FSM_NOT_SET,
    EXIT_FSM_INVALID,

    EXIT_DEV_MODE_NOT_SET,
    EXIT_DEV_MODE_INVALID,

    EXIT_NUM_STATES,

  }; // END enum


  // Declare Global FSM Exit Condition variables
  //----------------------------------------------------------------------------
    // extern keyword allows global vars to be accessible to all other program files
    // declare in .h, but MUST define / initialize in .cpp
  //extern exitConditionEnum sessionExitCondition;
  //extern exitConditionEnum stageExitCondition;

  // Enum Strings stored in PROGMEM
  //----------------------------------------------------------------------------
    // const char descriptions [NUMBER_OF_ELEMENTS] [MAX_SIZE] PROGMEM = {
    // http://www.gammon.com.au/forum/?id=12615
    const char exitConditionString [EXIT_NUM_STATES] [ENUM_STRING_BUFFER_SIZE] PROGMEM =
    {
      {"EXIT_NOT_SET"},                    // default to catch uninitialized states

      {"EXIT_STG_TIMEOUT"},

      {"EXIT_SES_TIMEOUT"},
      {"EXIT_SES_ALERT_1"},

      {"EXIT_FSM_NOT_SET"},
      {"EXIT_FSM_INVALID"},

      {"EXIT_DEV_MODE_NOT_SET"},
      {"EXIT_DEV_MODE_INVALID"},

    };  // END -- exitConditionString[][]


//==============================================================================
// == Function Prototypes == //
//==============================================================================

//bool fsmSetNextState(enum fsmEnum);
//bool goToFsmStateNext();

#endif  // -- END FSM_CONFIG_H

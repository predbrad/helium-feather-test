# Firmware Template Outline

Firmware template for a [non-preemptive multi-tasking](https://en.wikipedia.org/wiki/Cooperative_multitasking) application based on a [finite state machine (FSM)](https://en.wikipedia.org/wiki/Finite-state_machine) model.

---
## `app_config.h`
Define configuration and settings parameters for application firmware in a single, easily editable location.<br>

* App Info
  * `FIRMWARE_VERSION`
  * `FIRMWARE_NAME`
* App Settings
* Pin Configuration
* Peripheral Settings
  * Serial Settings
  * EasyButton Settings
  * NeoPixel Settings _(application dependent)_
* General Macros
---
## `main.cpp`

<img src="/img/" alt=".jpg" width="600">

**Application Code Outline**:

* **`#include`** Dependencies
  * Application Files
  * Arduino Standard Libraries
  * C Standard Libraries
  * Contributor Libraries
* Declare Global Variables
* Declare Global Objects
* Function Prototypes
* Function Definitions
  * EasyButton Callback Functions
  * Custom Interrupt Service Routines _(application dependent)_
  * Print Helper Functions
  * Other Custom Functions<br><br>

* **`setup()`**
  * I/O Pin Configuration
    * Initialize Output Pin States
    * Initialize Analog Input Range `AREF` _(application dependent)_
  * Object Setup
  * Attach Interrupts _(application dependent)_
  * Initialize Global Variables
  * Setup Device Operating Mode
    * `waitForUser()` _(device mode dependent)_
    * `printAppInfo()`
  * `setup()` Exit Actions<br><br>

* **`loop()`**
  * Service Watchdog Timer
  * Declare & Update `loop()` Variables
  * Handle Inputs
    * Handle Polled Inputs
    * Handle ISR Input Flags _(application dependent)_<br><br>

  * **Finite State Machine**
    * `FSM_SESSION_INITIALIZE`<br><br>

    * `FSM_SESSION_SETUP_WAIT_FOR_START` _(application dependent)_
    * `FSM_SESSION_RUN_WAIT_FOR_START` _(application dependent)_
    * `FSM_SESSION_EXIT_WAIT_FOR_START` _(application dependent)_<br><br>

      * `FSM_STAGE_SETUP_STAGE1`
      * `FSM_STAGE_RUN_STAGE1`
      * `FSM_STAGE_EXIT_STAGE1`
      * `...`<br><br>

    * `FSM_SESSION_COUNT_CHECK`_(application dependent)_<br><br>

    * `FSM_SESSION_SETUP_COMPLETED`
    * `FSM_SESSION_RUN_COMPLETED`
    * `FSM_SESSION_EXIT_COMPLETED`<br><br>

    * `FSM_SESSION_SETUP_ALERT` _(application dependent)_
    * `FSM_SESSION_RUN_ALERT` _(application dependent)_
    * `FSM_SESSION_EXIT_ALERT` _(application dependent)_<br><br>

  * Update Outputs
    * Update Actuator Outputs
    * Update Indicator LEDs
    * Update Pixel Scenes _(application dependent)_
    * Update Buzzer
    * Update Serial Monitor

---
<!--
## Descriptions

### Include Dependencies
### Application Files
### Arduino Standard Libraries
### C Standard Libraries
### Contributor Libraries

### Declare Global Variables
* Declare Variables whose value must persist beyond iterations of the main `loop()`

### Declare Global Objects
* Declare Objects defined by libraries included in [#Include Dependencies](#include-dependencies)

### Define Application Functions
* Custom functions defined for this application

### `setup()`
* Run once at system start-up

### I/O Pin Configuration
### Initialize Output Pin States
* Ensure outputs are set to intended initial states immediately

### Object Setup
* Call `.begin()` and perform setup procedure for objects declared in [Declare Global Objects](#declare-global-objects)

### Attach Interrupts

### `waitForUser()`
-->

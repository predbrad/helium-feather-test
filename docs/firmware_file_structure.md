# Firmware File Structure

Firmware template for a [non-preemptive multi-tasking](https://en.wikipedia.org/wiki/Cooperative_multitasking) application based on a [finite state machine (FSM)](https://en.wikipedia.org/wiki/Finite-state_machine) model.

---

## <img src="/img/arduino_icon.png" alt="arduino_icon.png" width="20"> <img src="/img/folders.png" alt="folders.png" width="20"> arduino_ide
May include basic code examples used to test and validate features and capabilities of libraries (typically based on examples from libraries). Once demonstrated in these examples, code snippets will be incorporated into the [`main.cpp`](#main.cpp) file used by PlatformIO.

---
## <img src="/img/platformio_icon.png" alt="platformio_icon.png" width="20"> <img src="/img/folders.png" alt="folders.png" width="20"> platformio_ide

Contains the complete application firmware (including library dependencies) and configuration required to compile using the [PlatformIO IDE](https://docs.platformio.org/en/latest/integration/ide/pioide.html).

### <img src="/img/file.png" alt="file.png" width="20">  `platformio.ini`
`[project_name]/firmware/platformio_ide/[app_name]/platformio.ini`

**Project Configuration File** used by PlatformIO IDE. More information is available at [platformio.ini - Project Configuration File](https://docs.platformio.org/en/latest/projectconf/index.html)

* [`[platformio]`](https://docs.platformio.org/en/latest/projectconf/section_platformio.html)
  * [`default_envs =`](https://docs.platformio.org/en/latest/projectconf/section_platformio.html#default-envs) set the environment(s) (boards) that PlatformIO will compile for
    * e.g. `uno`, `nano`, `adafruit_feather_m0`
<br><br>
* [`[env]`](https://docs.platformio.org/en/latest/projectconf/section_env.html) settings common to all environments
  * [`upload_port =`](https://docs.platformio.org/en/latest/projectconf/section_env_upload.html#upload-port) explicitly set the **COM Port** used to upload firmware to the device. This only needs to be set if automatic COM Port detection fails when attempting to upload code to the device
    * e.g. `COM3`
<br><br>
  * [`lib_deps =`](https://docs.platformio.org/en/latest/projectconf/section_env_library.html#lib-deps) list of libraries used by firmware that are common to all environments

### <img src="/img/folders.png" alt=".jpg" width="20"> `Libraries`
`[project_name]/firmware/platformio_ide/[app_name]/pio/libdeps/[board]/[libraries]`

Contains all libraries used by the firmware as well as example code for each library (if available)

### <img src="/img/file.png" alt="file.png" width="20"> `app_config.h`
`[project_name]/firmware/platformio_ide/[app_name]/src/app_config.h`

Application-specific configuration settings and `#define` macros in a single, easily editable location<br>

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

### <img src="/img/file.png" alt="file.png" width="20"> `main.cpp`
`[project_name]/firmware/platformio_ide/[app_name]/src/main.cpp`

Main firmware application code
<br><br>
<img src="/img/diagrams.net_icon.jpg" alt="diagrams.net_icon.jpg" width="15"> [`Generic FSM Firmware Diagram v1.0`](https://app.diagrams.net/#G14OYMjs0PxQFbcpyZN2r5fM-NseWNU7HY)
<img src="/img/generic_fsm_firmware_diagram.png" alt="generic_fsm_firmware_diagram.png">

# <img src="/img/cli_icon.png" alt="cli_icon.png " width="30"> Command Line Interface Guide

| [Command Line Interface (CLI)](#Command-Line-Interface-(CLI)) | [Serial Terminal Setup](#Serial-Terminal-Setup) |

The command line interface (CLI) provides a text-based method of interacting with the device using a Serial Terminal program on a PC. Device interactions may include setting variables, reading values, changing device modes, etc.


## Command Line Interface (CLI)
Start by opening a Serial Terminal program as described in [**Serial Terminal Setup**](#Serial-Terminal-Setup) below.

### Command Format
```
cmd -argument1 value1 -argument2 value2 ...
```
* **`cmd`**: is the command name (or alias)
* **`-argument1`**: is a defined command argument (or alias). Arguments are always preceded by a `-`
* **`value1`**: is the value that is being assigned to the `-argument` preceding it (if applicable). Some `-arguments` may not that require a `value` be specified.
* additional `-arguments` and `values` can be chained together in a single command

### Commands

<!--
#### `> pressure`
Transmit a pressure reading, change the pressure units, or zero-out the current pressure
* **Examples**:
  * `>` `pressure -unit k`
  * `>` `p -u k`
  * `>` `pressure -zero`
  * `>` `p -z`
  * `>` `p`
<br><br>
* **Name(s)**: `pressure`, `press`, `p`
* **Arguments & Values**:
  * `-unit`, `-u`
    * `c`: cmH2O **(default)**
    * `m`: mmH2O
    * `i`: inH2O
    * `k`: kPa
    * `p`: Pa
  * `-zero`, `-z`
    * None
-->


#### `> help`
Print list of available commands
* **Examples**:
  * `>` `help`<br>
  * `>` `h`
<br><br>
* **Name(s)**: `help`, `h`
* **Arguments & Values**:
  * None



#### `> set`
Set one or more variable values
* **Examples**:
  * `>` `set -debugLevel v -deviceMode n -fsmStateNow di -uiButton 1`
  * `>` `s -dbg v -dev n -fsm di -btn 1`
<br><br>
* **Name(s)**: `set`, `s`
* **Arguments & Values**:
  * `-debugLevel`, `-debug`, `-dbg`
    * `n`: DBG_NONE
    * `e`: DBG_ERROR
    * `w`: DBG_WARNING
    * `i`: DBG_INFO
    * `d`: DBG_DEBUG
    * `v`: DBG_VERBOSE
  * `-deviceMode`, `-device`, `-dev`
    * `n`: NORMAL_MODE
    * `f`: FIRST_RUN_MODE
    * `s`: SETUP_MODE
    * `d`: DEVELOPMENT_MODE
    * `t`: TEST_MODE
    * `b`: BURN_IN_MODE
  * `-fsmStateNow`, `-fsmState`, `-fsm`
    * `di`: FSM_SYS_INIT_DEV
    * `w` : FSM_SYS_WAIT
    * `ai`: FSM_SYS_INIT_APP
    * `si`: FSM_SES_INIT
    * `s1`: FSM_STG_INIT_STAGE1
    * `a` : FSM_SYS_INIT_ALERT
    * `e` : FSM_SYS_INIT_ERROR
  * `-uiButton`, `-uiBtn`, `btn`
    * `press`, `1`: button pressed
    * `hold`, `2`: button held
<!--  * `-fanState`, `-fan`
    * `0`: Off
    * `1`: On
  * `-fanSpeedPwm`, `-fanSpeed`, `-pwm`
    * `0` to `255`: PWM value
-->  

---
## Serial Terminal Setup

### <img src="/img/arduino_icon.png" alt="arduino_icon.png" width="20"> Arduino IDE Serial Monitor

The `Serial Monitor` function included with the Arduino IDE is one of the simplest serial terminal programs to use, and one that many Arduino users are already familiar with. You do not need to use the code window of the Arduino IDE to use `Serial Monitor` function - they operate independently.
#### Setup

1. Download and install the <img src="/img/arduino_icon.png" alt="arduino_icon.png" width="15"> [Arduino IDE](https://www.arduino.cc/en/software) (if you haven't already)
1. Connect the target device to the PC with a USB cable
1. Open <img src="/img/arduino_icon.png" alt="arduino_icon.png" width="15"> Arduino IDE
1. Go to `Tools > Port` and make sure the target device **COM Port** is selected<br>
    In this example, `COM6`<br>
    <img src="/img/arduino_ide_com_port.png" alt="arduino_ide_com_port.png" width="400">
1. Click the <img src="/img/arduino_serial_monitor_icon.png" alt="arduino_serial_monitor_icon.png" width="15"> **Serial Monitor** button in the toolbar <br>
    <img src="/img/arduino_ide_toolbar_serial_monitor.png" alt="arduino_ide_toolbar_serial_monitor.png" width="400">
1. Set `baud` to match `SERIAL_BAUD_RATE` from `app_config.h`<br>
    <img src="/img/arduino_ide_serial_baud.png" alt="arduino_ide_serial_baud.png" width="400">
1. Type `help` and click `Send`<br>
    If the serial connection is valid, the device will respond with a list of available CLI commands <br>
    <img src="/img/arduino_ide_serial_help.png" alt="arduino_ide_serial_help.png" width="600">

### <img src="/img/realterm_icon.png" alt="realterm_icon.png" width="20"> RealTerm

RealTerm is another free serial terminal program with more advanced features such as:
* capture data to a `.txt` file
* send / display data as `HEX` byte values
* define port settings (Parity, Data Bits, Stop Bits, Hardware Flow Control)
* monitor / spy on serial communication between other devices

[RealTerm Documentation](https://realterm.sourceforge.io/)<br>
[Sparkfun RealTerm Tutorial](https://learn.sparkfun.com/tutorials/terminal-basics/real-term-windows)

#### Setup
1. Download and install the latest version of <img src="/img/realterm_icon.png" alt="realterm_icon.png" width="15"> [RealTerm v3+ ](https://realterm.i2cchip.com/)
1. Connect the target device to the PC with a USB cable
1. Open <img src="/img/realterm_icon.png" alt="realterm_icon.png" width="15"> RealTerm
1. In the **Port** tab:
    * Set **Baud** to match `SERIAL_BAUD_RATE` from `app_config.h`
    * Set **Port** to the device COM Port number, in this example `6` (`COM6`)
    * Click **`Open`** _twice_ to refresh the port settings
      * You should see your selected settings in the bottom right corner<br>

    <img src="/img/realterm_port_tab.png" alt="realterm_port_tab.png" width="600">
1. In the **Display** tab, under **Display As**:
    * **Uncheck** the box for _Clear Terminal when Display Changes_
    * Select **Ascii plain**<br>

    <img src="/img/realterm_display_tab.png" alt="realterm_display_tab.png" width="600">

1. In the **Send** tab:
    * Type `help` in the first text field
    * Click **`as ASCII`**<br>

    If the serial connection is valid, the device will respond with a list of available CLI commands <br>

    <img src="/img/realterm_send_tab.png" alt="realterm_send_tab.png" width="600">

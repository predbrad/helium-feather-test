# <img src="/img/platformio_icon.png" alt="platformio_icon.png" width="30"> PlatformIO IDE Guide

## Overview
* [Installing <img src="/img/platformio_icon.png" alt="platformio_icon.png" width="15"> PlatformIO](#Installing-PlatformIO)
* [Start a New Project from Template](#Start-a-New-Project-from-Template)
  * [Create a New Project with <img src="/img/github_icon.png" alt="github_icon.png" width="15"> GitHub](#Create-a-New-Project-with-GitHub)
  * [Clone Project Repo to PC with <img src="/img/sourcetree_icon.png" alt="sourcetree_icon.png" width="15"> SourceTree](#Clone-Project-Repo-to-PC-with-SourceTree)
  * [Configure Project with <img src="/img/platformio_icon.png" alt="platformio_icon.png" width="15"> PlatformIO](#Configure-Project-with-PlatformIO)
* [Download a Project as <img src="/img/zip_icon.png" alt="zip_icon.png" width="15"> Zip from <img src="/img/github_icon.png" alt="github_icon.png" width="15"> GitHub](#Download-a-Project-as-Zip-from-GitHub)
* [Open a Project from <img src="/img/zip_icon.png" alt="zip_icon.png" width="15"> Zip with <img src="/img/platformio_icon.png" alt="platformio_icon.png" width="15"> PlatformIO](#Open-a-Project-from-Zip-with-PlatformIO)
* [Uploading Firmware to a Device with <img src="/img/platformio_icon.png" alt="platformio_icon.png" width="15"> PlatformIO](#Uploading-Firmware-to-a-Device-with-PlatformIO)

<br>

PlatformIO's official documentation: [**Docs >> PlatformIO IDE**](https://docs.platformio.org/en/latest/integration/ide/pioide.html)

PlatformIO is a free, professional firmware development platform that provides features and capabilities which are not offered by the Arduino IDE, such as:
* **project portability** - libraries are contained within the project itself
* **library version management** - ensures updates to libraries won't break tested firmware
* **project configuration file** - project configuration is saved with the project, not determined by settings in the local IDE
* **single code source for multiple boards** - project configuration allows for dynamic compilation, such as which libraries are used to compile with various MCUs
* **alleviates file path limitations** - Arduino IDE has a file path character limit that can cause compilation failures
* ... and more at [PlatformIO.org](https://platformio.org/)

<img src="/img/platformio_icon.png" alt=".jpg" width="15"> PlatformIO runs as an extension inside of other core programs such as <img src="/img/visual_studio_icon.png" alt="visual_studio_icon.png" width="15"> Microsoft Visual Studio Code or <img src="/img/atom_icon.png" alt="atom_icon.png" width="15"> Atom. These instructions will focus on use with <img src="/img/visual_studio_icon.png" alt="visual_studio_icon.png" width="15"> Microsoft Visual Studio Code.

---

## Installing PlatformIO

1. Download and Install <img src="/img/visual_studio_icon.png" alt="visual_studio_icon.png" width="15"> [Microsoft Visual Studio Code](https://code.visualstudio.com/)

1. Open <img src="/img/visual_studio_icon.png" alt="visual_studio_icon.png" width="15"> Visual Studio Code and go to `File > Preferences > Extensions`

1. Search for `platformio ide` and click **Install**<br>
    <img src="/img/platformio_extension_install.png" alt=".jpg" width="400">

1. Once completed, you'll see
    * [PlatformIO Home Page](https://docs.platformio.org/en/latest/home/index.html#piohome)
    * PlatformIO Home Button (side bar)
    * [PlatformIO Toolbar](https://docs.platformio.org/en/latest/integration/ide/vscode.html#ide-vscode-toolbar) (bottom)<br>
    <img src="/img/platformio_home.png" alt="platformio_home.png" width="400">

## Start a New Project from Template

To start a new project using our `_Template_Project`:
* Use <img src="/img/github_icon.png" alt="github_icon.png" width="15"> **GitHub.com** to create a new project from our `_Template_Project`
* Use <img src="/img/sourcetree_icon.png" alt="sourcetree_icon.png" width="15"> **SourceTree** to clone the project repo to our local PC
* Use <img src="/img/platformio_icon.png" alt=".jpg" width="15"> **PlatformIO** to configure the project for development

### Create a New Project with GitHub

1. In <img src="/img/github_icon.png" alt="github_icon.png" width="15"> GitHub, go to the  [_Template_Project](https://github.com/MattStarfield/_Template_Project) repository and click **Use this Template**<br>
    <img src="/img/github_use_template.png" alt="github_use_template.png" width="400">

1. Choose a unique **Repository Name**, select **Private**, and click **Create repository from template**<br>
    <img src="/img/github_create_new_repo.png" alt="github_create_new_repo.png" width="400">

### Clone Project Repo to PC with SourceTree

1. Create a new folder to contain the project repo on your PC, e.g. `C:/Git/Example_Project`

1. Open <img src="/img/sourcetree_icon.png" alt="sourcetree_icon.png" width="15"> SourceTree and go to **File > Clone / New**

1. Click <img src="/img/sourcetree_remote_icon.png" alt="sourcetree_remote_icon.png" width="20">  **Remote**

1. Find the project repo you wish to clone from the list and click **Clone**<br>
    <img src="/img/sourcetree_remote_repositories.png" alt="sourcetree_remote_repositories.png" width="400">

1. Click **Browse** and select the container folder we created above, then click **Clone**<br>
    <img src="/img/sourcetree_clone.png" alt="sourcetree_clone.png" width="400">

1. This will copy the entire project repo into the folder on your PC, and configure the connection between <img src="/img/github_icon.png" alt="github_icon.png" width="15"> GitHub and <img src="/img/sourcetree_icon.png" alt="sourcetree_icon.png" width="15"> SourceTree to allow project updates and syncronization.

### Configure Project with PlatformIO

1. On your PC, navigate to `[Project Repo Location]/firmware/platformio_ide/`and change the project firmware folder name from `_template_project_name` to the actual project name, e.g. `example_project`

1. Open <img src="/img/visual_studio_icon.png" alt="visual_studio_icon.png" width="15"> Visual Studio Code and click the <img src="/img/platformio_home_icon.png" alt="platformio_home_icon.png" width="15"> **Home** button in the bottom toolbar to open the <img src="/img/platformio_icon.png" alt=".jpg" width="15"> PlatformIO **Home Page**<br>
    <img src="/img/platformio_toolbar_home_button.png" alt="platformio_toolbar_home_button.png" width="400">

1. From the PlatformIO Home Page, click **Open Project**<br>
    <img src="/img/platformio_open_project.png" alt="platformio_open_project.png" width="400">

1. Navigate to the `platformio.ini` file within the project folder, and click **Open**<br>
    e.g. `[Project Folder Location]/[project_name]/firmware/platformio_ide/[app_name]`<br>
    <img src="/img/platformio_open_project2.png" alt="platformio_open_project2.png" width="400">

1. You should now see the project open in the Explorer side bar<br>
    <img src="/img/platformio_open_project3.png" alt="platformio_open_project3.png" width="200">

1. Click the <img src="/img/platformio_build_icon.png" alt="platformio_build_icon.png" width="15"> **Build** button in the bottom toolbar to compile the project code<br>
    <img src="/img/platformio_toolbar_build_button.png" alt="platformio_toolbar_build_button.png" width="400">

1. A terminal window will appear and the project code should compile with Status: **SUCCESS**<br>
    <img src="/img/platformio_build_success.png" alt="platformio_build_success.png" width="400">

1. To change the Project Configuration, Click the <img src="/img/platformio_projects_icon.png" alt="platformio_projects_icon.png" width="15"> **Projects** button to open the Projects Page

1. Locate the project from the list and click **Configure**<br>
    <img src="/img/platformio_configure.png" alt="platformio_configure.png" width="400">

1. In the Configuration Page, click the **default** tab to modify the default project environment.
    * **platform** - select the device platform, e.g. `atmelavr`, `atmelsam`, `espressif32`
    * **board** - select the development board, e.g. `uno`, `nanoatmega328new`, `adafruit_feather_m0`
    * **+ Add Library** - to include additional libraries in the project<br>

    Then click **Save**<br>
    <img src="/img/platformio_configure2.png" alt="platformio_configure2.png" width="400">

1. Click the <img src="/img/platformio_build_icon.png" alt="platformio_build_icon.png" width="15"> **Build** button to recompile the code for the new configuration

## Download a Project as Zip from GitHub

1. Go to the <img src="/img/github_icon.png" alt="github_icon.png" width="15"> GitHub Project page and click **Code > Download ZIP**<br>
  <img src="/img/github_repo_download.png" alt="github_repo_download.png" width="250">
1. Extract the project <img src="/img/zip_icon.png" alt="zip_icon.png" width="15"> .Zip file to the desired location on your PC

## Open a Project from Zip with PlatformIO

1. Open <img src="/img/visual_studio_icon.png" alt="visual_studio_icon.png" width="15"> Visual Studio Code and click the <img src="/img/platformio_home_icon.png" alt="platformio_home_icon.png" width="15"> **Home** button in the bottom toolbar to open the <img src="/img/platformio_icon.png" alt=".jpg" width="15"> PlatformIO **Home Page**<br>
    <img src="/img/platformio_toolbar_home_button.png" alt="platformio_toolbar_home_button.png" width="400">

1. From the PlatformIO Home Page, click **Open Project**<br>
    <img src="/img/platformio_open_project.png" alt="platformio_open_project.png" width="400">

1. Navigate to the `platformio.ini` file within the project folder, and click **Open**<br>
    e.g. `[Project Folder Location]/[project_name]/firmware/platformio_ide/[app_name]`<br>
    <img src="/img/platformio_open_project2.png" alt="platformio_open_project2.png" width="400">

1. You should now see the project open in the Explorer side bar<br>
    <img src="/img/platformio_open_project3.png" alt="platformio_open_project3.png" width="200">

1. Click the <img src="/img/platformio_build_icon.png" alt="platformio_build_icon.png" width="15"> **Build** button in the bottom toolbar to compile the project code<br>
    <img src="/img/platformio_toolbar_build_button.png" alt="platformio_toolbar_build_button.png" width="400">

1. A terminal window will appear and the project code should compile with Status: **SUCCESS**<br>
    <img src="/img/platformio_build_success.png" alt="platformio_build_success.png" width="400">

## Uploading Firmware to a Device with PlatformIO
1. Complete the steps in [**Open an Existing Project**](#Open-an-Existing-Project)

1. You should see the project open in the Explorer side bar<br>
    > If you don't see the Explorer bar, click `View > Explorer`<br>

    <img src="/img/platformio_open_project3.png" alt="platformio_open_project3.png" width="200">

1. Connect the target device to the PC with a USB cable

1. Click the <img src="/img/platformio_upload_icon.png" alt="platformio_upload_icon.png" width="15"> **Upload** button in the bottom toolbar <br>
    <img src="/img/platformio_toolbar_upload_button.png" alt="platformio_toolbar_upload_button.png" width="400">

1. PlatformIO will attempt to automatically detect the correct **COM Port** and upload the firmware <br>
    <img src="/img/platformio_auto_detect_com_port.png" alt="platformio_auto_detect_com_port.png" width="300">

>If automatic **COM Port** detection fails, select a **COM Port** manually with the following steps...<br>

6. Click the <img src="/img/platformio_terminal_icon.png" alt="platformio_terminal_icon.png" width="15"> **Terminal** button in the bottom toolbar <br>
    <img src="/img/platformio_toolbar_terminal_button.png" alt="platformio_toolbar_terminal_button.png" width="400">

1. Type [`pio device list`](https://docs.platformio.org/en/latest/core/userguide/device/cmd_list.html#cmd-device-list) and press **Enter** to generate a list of available **COM Ports**. Identify the COM Port for the target device.<br> In this example, `COM6`<br>
    <img src="/img/platformio_device_list.png" alt="platformio_device_list.png" width="400">

1. Now, open the file `platformio.ini` and under the `; Serial Port Settings` section, add the line [`upload_port = COMx`](https://docs.platformio.org/en/latest/projectconf/section_env_upload.html?highlight=upload_port#upload-port) where `x` is the desired **COM Port** value.<br> In this example, `upload_port = COM6`<br>
    <img src="/img/platformio_upload_port.png" alt="platformio_upload_port.png" width="400">

1. Click `File > Save` to save the changes to `platformio.ini`

1. Click the <img src="/img/platformio_upload_icon.png" alt="platformio_upload_icon.png" width="15"> **Upload** button in the bottom toolbar <br>
    <img src="/img/platformio_toolbar_upload_button.png" alt="platformio_toolbar_upload_button.png" width="400">

1. To re-enable automatic COM Port detection, simply remove the `upload_port = COMx` line from `platformio.ini` and save.

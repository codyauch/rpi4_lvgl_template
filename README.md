# Raspberry Pi 4 LVGL Touchscreen Template
This repo is meant to be a configuration template for running LVGL on a Raspberry Pi 4 with a TFT touchscreen. Once the template is installed and running, modifications may be made to suit your project.
## Hardware
- Raspberry Pi 4
- 7" Touchscreen Monitor connected via ribbon cable

##  Initial Setup
- Download and install Raspberry Pi OS Lite (64-bit) on the Raspberry Pi.
- Clone this repository on the Raspberry pi, including submodules:
```bash
$ git clone --recurse-submodules https://github.com/codyauch/rpi4_lvgl_template
```
## Configuring the touchscreen
Input from the touchscreen can be accessed via an event device, or evdev, typically located at /dev/input/event*. To determine which evdev represents the touchscreen, install and run the 'evtest' tool.
```bash
$ sudo apt install evtest
$ evtest
```
Once the touchscreen's evdev is found (mine is /dev/input/event4), use the device path to configure an `lv_indev_t` pointer in [main.c](https://github.com/codyauch/rpi4_lvgl_template/blob/284e755dd312e6e3fe3a0d57ec2006672e1a4571/main.c#L21)
## Compiling
At the root of the repository, use the `make` command to compile the program. To improve compilation time, the `lvgl/demos` and `lvgl/examples` directories can be removed.

## Running
To start the program, run the compiled binary:
```bash
$ sudo ./build/bin/main
```
The screen should display a blue "Click Me" button at the centre of the screen, and when clicked the text will change to "Touch Registered"

## Relevant LVGL Documentation
- [Linux Evdevs](https://docs.lvgl.io/master/details/integration/driver/touchpad/evdev.html)
- [Linux Framebuffer](https://docs.lvgl.io/master/details/integration/driver/display/fbdev.html)

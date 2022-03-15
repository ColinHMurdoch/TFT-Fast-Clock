# TFT-Fast-Clock

Adjustable Speed Time Clock for Model Railway Operation using a TFT/LCD display.

## Background

This project is based on a project written by Jim Gifford (Hallet Cove Southern) in June 2017.  This project used a 32 x 8 LED matrix to display the time and was controlled by a nuber of pushbuttons.
[See Jim's Original Project here.](https://www.hallettcovesouthern.com/track-plan-design-info/arduino-projects/fast-clock/)

I felt that this project was ripe for an update and decided to convert Jim's code to operate using a cheap TFT/LCD touch screen to run on my own layout. This project is the result.  Much of the code has been rewritten into smaller functions with additional features added, but the time clock calculations are the originals.

## Hardware

The project uses only two components:
1.  A standard arduino or compatable clone.
2.  A 2.8" MCUFRIEND style TFT-LCD plug-in shield.

The completed project is shown in the accompanying photograph:


![TFT Fast Clock](/images/IMG_2502.jpg)

## Operation

At startup the clock will calculate a start time based on either a) a coded start time (currently 6:00 a.m.) or b) a run time stored in the EEPROM (see item 2) below.

The clock will start in a paused state and will display the speed rate factor (default = x 4).  Once any adjustemts have been made the clock can be started.  The usage of the six buttons are as below:

1. **Start** - Pressing this button will start the clock and the button text will change to **Pause**.  
2. **Save** - Pressing this button will pause the clock and save the current time and Speed Factor to the EEPROM.  These figures will be used to initialise the clock on nextstartup.
3. **Reset** - Pressing this button will pause the clock and set the time to 06:00 with a speed factor of 4.
4. **T+** - Pressing this key will pause the clock and add 15 minutes to the time.
5. **T-** - Pressing this key will pause the clock and deduct 15 minutes from the time.
6. **Rate** - Pressing this key will increase the speed factor to the next level.  The speed factor will cycle around the seven speed settings of 1, 2, 4, 6,, 8, 12 & 30.


## Installation Notes

The project requires three libraries - Adafruit_GFX, Adafruit_Touchscreen and MCUFRIEND_kbv.  All three cn be installed from the Arduino IDE library manager.

I have also generated two special fonts for the project which can be found in the Fonts folder in this repository.  These should be copied into the fonts folder in the Adafruit_GFX library once installed.






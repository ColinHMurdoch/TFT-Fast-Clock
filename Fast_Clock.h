#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

#include <TouchScreen.h>
#include <EEPROM.h>

#define MINPRESSURE 200
#define MAXPRESSURE 1000

#include <SPI.h>

// ALL Touch panels and wiring is DIFFERENT
// copy-paste results from TouchScreen_Calibr_native.ino
//These settings are for the McuFriend 2.8" shield

const int XP = 7, XM = A1, YP = A2, YM = 6;
//const int TS_LEFT = 918, TS_RT = 122, TS_TOP = 99, TS_BOT = 895; // for Portrait Orientation
//const int TS_LEFT = 99, TS_RT = 895, TS_TOP = 122, TS_BOT = 918;  // For Landscape Orientation
const int TS_LEFT = 123, TS_RT = 923, TS_TOP = 895, TS_BOT = 98; // for Portrait orientation 2

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

//Adafruit_GFX_Button in_btn, out_btn, run_btn, estop_btn;
Adafruit_GFX_Button btn1, btn2, btn3, btn4, btn5, btn6;

int pixel_x, pixel_y;     //Touch_getXY() updates global vars


#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// #define MAX_DEVICES 4
// #define CLK_PIN   13  // or SCK
// #define DATA_PIN  11  // or MOSI
// #define CS_PIN    10  // or SS
// // Text parameters
// #define  CHAR_SPACING  1 // pixels between characters


// Global message buffers shared by Serial and Scrolling functions
#define BUF_SIZE  15
char message[BUF_SIZE] = {"Hello!"};
//bool newMessageAvailable = true;


unsigned long currentMillis = 0;  //  Current Millis value for comparison
unsigned long lastMillis = 0;     //  Last Millis for comparison
unsigned long startTime = 0;      //  Milliseconds since 00:00.000 to Session Start Time
unsigned long runTime = 0;        //  Milliseconds since Session Start Time

// Constants
const int milPerSec = 1000;       //  Milliseconds per Second
unsigned long milPerMin = 60000;  //  Milliseconds per minute
unsigned long milPerHr = 3600000; //  Milliseconds per Hour

int clockSpeeds[] = {1, 2, 4, 6, 8, 12, 30};  //  Fast Clock Speeds
int clockSpeed = 4;               //  Initial Fast Clock Speed Setting
int debounceDelay = 75;           //  the debounce time; increase if the output flickers
int counter = 2;                  //  for program logic

bool pausePlay = false;            //  clock state - running or paused

int HH;                           //  Integer Hours
int MM;                           //  Integer Minutes
int HD;                           //  number of full Days since conting
int MH;                           //  number of full hours since conting
int SM;                           //  number of full minutes since conting 
int Ss;                           //  Integer Seconds 
String Time;                      //  Character Hours:Minutes
String TimeP;                     //  Character Hours:Minutes:Seconds
String Hour;                      //  Character Hours
String Minute;                    //  Character Minutes + ":"
String MinuteS;                   //  Character Minutes
String Second;                    //  Character Seconds
String Speed;                     //  Character Speed
String Pause;                     //  Character Pause
int LastMinutes = 99;

int ButtonPressed = 0;

struct MyTime {
  int hour;
  int minute;
  int speed;
};

MyTime PauseTime;

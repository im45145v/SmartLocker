#include <ESP8266Firebase.h>
#include <ESP8266WiFi.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#define FINGERPRINT "A1:B8:E0:02:42:47:38:1D:84:1B:3C:HG:1F:6D:B8:GG:13:77:GG:GG"
#define _SSID ""   
#define _PASSWORD ""    
#define PROJECT_ID "otp-generator-12592" 
Firebase firebase(PROJECT_ID, FINGERPRINT);
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};byte rowPins[ROWS] = {D1, D2, D3, D4};  
byte colPins[COLS] = {D5, D6, D7, D8};
//columns connected to digital pins of nodemcu

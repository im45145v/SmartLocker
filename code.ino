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


void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to: ");
  Serial.println(_SSID);
  WiFi.begin(_SSID, _PASSWORD);
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
  digitalWrite(LED_BUILTIN, HIGH);
  pinMode(relayInput, OUTPUT); 
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Enter OTP: ");
}

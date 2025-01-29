#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>
#define REMOTEXY_SERIAL_RX 11
#define REMOTEXY_SERIAL_TX 10
#define REMOTEXY_SERIAL_SPEED 9600
#include <RemoteXY.h>

#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 66 bytes
  { 255,3,0,1,0,59,0,19,0,0,0,0,31,1,106,200,1,1,4,0,
  1,14,37,24,24,0,2,31,0,1,14,88,24,24,0,2,31,0,1,14,
  144,24,24,0,2,31,0,74,7,8,94,15,12,2,30,37,64,83,116,114,
  105,110,103,32,49,0 };

struct {
    uint8_t button_01;
    uint8_t button_02;
    uint8_t button_03;
    uint8_t strings_01;
    uint8_t connect_flag;
} RemoteXY;   
#pragma pack(pop)

char result[11];  // Buffer for string
int p = 0;
int i = 0;
int d = 0;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
bool lastButtonState = false;

void setup() 
{
  RemoteXY_Init(); 
  Serial.begin(115200);
}

void loop() 
{ 
  RemoteXY_Handler();

  if (RemoteXY.button_01 == 1) {

    if ((millis() - lastDebounceTime) > debounceDelay) {

      // p += 1;

      Serial.println("pressed");

      lastDebounceTime = millis();

    }

  }

}
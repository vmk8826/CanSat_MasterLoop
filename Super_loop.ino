#include <Adafruit_BMP280.h>
#include <Wire.h>
#include <String.h>
#include <SPI.h>
#include <RtcDS3231.h>
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include <Servo_ESP32.h>
RtcDS3231<TwoWire> Rtc(Wire);
#include "MPU9250.h"
//#include <MPU6050_light.h>
MPU9250 IMU(Wire, 0x69);
//MPU6050 mpu(Wire);

Adafruit_BMP280 bmp; // I2C
#define countof(a) (sizeof(a) / sizeof(a[0]));

Servo_ESP32 servo1;

String TEAM_ID = "1095";
String MISSION_TIME = "";
int PACKET_COUNT = 1;
char PACKET_TYPE = 'T';
float TP_ALTITUDE =NULL;
float TP_TEMP = NULL;
String TP_VOLTAGE ="";
String GYRO_R ="";
String GYRO_P ="";
String GYRO_Y ="";
String ACCEL_R ="";
String ACCEL_P ="";
String ACCEL_Y ="";
String MAG_R ="";
String MAG_P ="";
String MAG_Y ="";
String POINTING_ERROR ="30";
String TP_SOFTWARE_STATE ="2";
String Data_Packet = "";

void setup() 
{
  Serial.begin(115200);
  Wire.begin(15, 2, 400000);
  Serial2.begin(115200);
  IMU_set();
  /*delay(10);
  Servo_set();*/
  delay(10);
  BMP_set();
  delay(10);
  RTC_set();
  delay(10);
  SDCard_set();
  delay(10);
  Voltage_set();
  delay(10);
}

void loop() {  
  IMU_data();
  delay(5);
  /*Camera_Stable();
  delay(10);*/
  BMP_data();
  delay(5);
  RTC_data();
  delay(5);
  Voltage_data();
  delay(5);
  Append_String();
  delay(5);
 SD_data();
  delay(10);
  Communication();
  delay(100);
  PACKET_COUNT++;
}

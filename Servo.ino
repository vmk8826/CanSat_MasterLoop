/*void Servo_set()
{
  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { } // stop everything if could not connect to MPU6050

  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  mpu.calcOffsets();
  servo1.attach(21);
  servo1.write(0);
}*/
/*
  void Camera_Stable()
  {
  unsigned long timer = 0;
  mpu.update();
  Serial.println(mpu.getAngleZ());M
  POINTING_ERROR = String(mpu.getAngleZ());

  if ((millis() - timer) > 10)
  {
  timer = millis();
  servo1.write(-mpu.getAngleZ());
  }
  }*/

void Camera_Stable()
{
  int minVal=265;
  int maxVal=402;
  int xAng = map(IMU.getAccelX_mss(), minVal, maxVal, -90, 90);
  int yAng = map(IMU.getAccelY_mss(), minVal, maxVal, -90, 90);
  int zAng = map(IMU.getAccelZ_mss(), minVal, maxVal, -90, 90);

  /*double x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI);
  double y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI);*/
  double z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);
  Serial.print("AngleZ= ");
  Serial.println(z);
}

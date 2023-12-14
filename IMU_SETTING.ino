void IMU_set(){
  int status;
  status = IMU.begin();
  if (status < 0) 
  {
    Serial.println("IMU initialization unsuccessful");
    Serial.println("Check IMU wiring or try cycling power");
    Serial.print("Status: ");
    Serial.println(status);
    while (1) {}
  }
}

void IMU_data()
{
  IMU.readSensor();
  GYRO_R = String(IMU.getGyroX_rads(), 6); 
  GYRO_P = String(IMU.getGyroY_rads(), 6);  
  GYRO_Y = String(IMU.getGyroZ_rads(), 6);
  ACCEL_R = String(IMU.getAccelX_mss(), 6);
  ACCEL_P = String(IMU.getAccelY_mss(), 6);
  ACCEL_Y = String(IMU.getAccelZ_mss(), 6);
  MAG_R = String(IMU.getMagX_uT(), 6);
  MAG_P = String(IMU.getMagY_uT(), 6);
  MAG_Y = String(IMU.getMagZ_uT(), 6);
  return;
}/*
void IMU_data()
{
 IMU.readSensor();
  // display the data
  Serial.print(IMU.getAccelX_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getAccelY_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getAccelZ_mss(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroX_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroY_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getGyroZ_rads(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagX_uT(),6);
  Serial.print("\t");
  Serial.print(IMU.getMagY_uT(),6);
  Serial.print("\t");
  Serial.println(IMU.getMagZ_uT(),6);
  delay(100);
}*/

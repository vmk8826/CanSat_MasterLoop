void Append_String()
{
  
  String IMU_DataString = make_IMU_string();
  String BMP_DataString = make_BMP_string();
  
  Data_Packet = TEAM_ID + ',' + MISSION_TIME + ',' + String(PACKET_COUNT)+ ',' 
  + PACKET_TYPE + ',' + BMP_DataString + ',' + TP_VOLTAGE + ',' +IMU_DataString + ',' + POINTING_ERROR+"\n";
 // communication_TXRX();
  Serial.print(Data_Packet);
}

String make_IMU_string()
{
  String IMU_dataTemp = "";
  IMU_dataTemp = GYRO_R + ',' + GYRO_P + ',' + GYRO_Y + ','
                 + ACCEL_R + ',' + ACCEL_P + ',' + ACCEL_Y + ','
                 + MAG_R + ',' + MAG_P + ',' + MAG_Y;
  return (IMU_dataTemp);
}

String make_BMP_string()
{
  String BMP_dataTemp = "";
  BMP_dataTemp = String(TP_ALTITUDE)+','+String(TP_TEMP);
  return (BMP_dataTemp);
}

void Communication()
{
  for (int i = 0; i < Data_Packet.length(); i++)
  {
    Serial2.write(Data_Packet[i]);
  }
  // Serial2.write(Data_Packet);
}

void communication_TXRX()
{
  Serial.println("waiting");
  int count = 1;
  char line = NULL;
  while (Serial2.available() <= 0)
  {
    delay(1);
    count++;
    if (count >= 200)
      break;
  }
  while (Serial2.available() > 0)
  {
    line = Serial2.read();
    //Serial2.println(line);
  }

  //Serial.println(line);
  if (line == 'S') {
    for (int i = 0; i < Data_Packet.length(); i++)
    {
      Serial2.write(Data_Packet[i]);
    }
  }
  delay(10);
  return;
}

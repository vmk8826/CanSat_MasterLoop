void Voltage_set()
{
  int Voltage_pin=35;
  pinMode(Voltage_pin,INPUT);
}

void Voltage_data()
{
  float volt_temp=0;
  volt_temp=analogRead(A7);
  volt_temp=(volt_temp*5.7)/4095;
  TP_VOLTAGE=String(volt_temp);
}

void BMP_set()
{
  unsigned status;

  status = bmp.begin(0x76);

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     // Operating Mode.
                  Adafruit_BMP280::SAMPLING_X2,     // Temp. oversampling
                  Adafruit_BMP280::SAMPLING_X16,    // Pressure oversampling
                  Adafruit_BMP280::FILTER_X16,      // Filtering.
                  Adafruit_BMP280::STANDBY_MS_500); // Standby time.
}

void BMP_data()
{
  TP_TEMP = (bmp.readTemperature());
  TP_ALTITUDE = (bmp.readAltitude(1013.25));
}

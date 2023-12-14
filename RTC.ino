void RTC_set()
{
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  Rtc.Enable32kHzPin(false);
  Rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone);
}

void printDateTime(const RtcDateTime& dt)
{
  char datestring[15];
  sprintf(datestring, "%02d:%02d:%02d", dt.Hour(), dt.Minute(), dt.Second());
  MISSION_TIME = String(datestring);
}

void RTC_data(){
  RtcDateTime now = Rtc.GetDateTime();
  printDateTime(now);
}

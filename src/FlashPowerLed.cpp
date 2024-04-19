void FlashPowerLED(void)

{
  if (_gPowerOnVBLs != 0) {
    _gPowerVBLs = _gPowerVBLs + 1;
    if ((DEV_LED & 4) == 0) {
      if (_gPowerOnVBLs != _gPowerVBLs) {
        return;
      }
     DEV_LED = DEV_LED | 4;
    }
    else {
      if (_gPowerOffVBLs != _gPowerVBLs) {
        return;
      }
      DEV_LED = DEV_LED & 0xfffffffb;
    }
    _gPowerVBLs = 0;
  }
  return;
}

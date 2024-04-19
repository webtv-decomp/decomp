void FlashMessageLED(void)

{
  if (_gMessageOnVBLs != 0) {
    _gMEVBLs = _gMEVBLs + 1;
    if ((DEV_LED & 1) == 0) {
      if (_gMessageOnVBLs != _gMEVBLs) {
        return;
      }
      DEV_LED = DEV_LED | 1;
    }
    else {
      if (_gMessageOffVBLs != _gMEVBLs) {
        return;
      }
      DEV_LED = DEV_LED & 0xfffe;
    }
    _gMEVBLs = 0;
  }
  return;
}

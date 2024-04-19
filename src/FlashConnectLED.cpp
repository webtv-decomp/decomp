void FlashConnectLED(void)

{
  if (_gConnectedOnVBLs != 0) {
    _gElapsedVBLs = _gElapsedVBLs + 1;
    if ((DEV_LED & 2) == 0) {
      if (_gConnectedOnVBLs != _gElapsedVBLs) {
        return;
      }
      DEV_LED = DEV_LED | 2;
    }
    else {
      if (_gConnectedOffVBLs != _gElapsedVBLs) {
        return;
      }
      DEV_LED = DEV_LED & 0xfffd;
    }
    _gElapsedVBLs = 0;
  }
  return;
}

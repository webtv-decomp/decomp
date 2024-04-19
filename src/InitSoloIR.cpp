void InitSoloIR(void)

{
  int GetManufacturer;
  
  _irSampleTail = 0;
  _irSampleHead = 0;
  SetSampleInterval(0xf);
  DEV_IRIN_REJECT_INT = 10;
  DEV_IRIN_STATCNTL = 0x3083;
  InitDecodeSony();
  InitDecodeSejin();
  InitDecodePhilips();
  InitDecodeEchoStar();
  GetManufacturer = System::GetManufacturer();
  switch(GetManufacturer) {
  case 0:
    IRDecodeFlags = IRDecodeFlags | 1;
    break;
  case 1:
    IRDecodeFlags = IRDecodeFlags | 2;
    break;
  default:
    IRDecodeFlags = IRDecodeFlags | 4;
    break;
  case 0xffffffff:
    IRDecodeFlags = IRDecodeFlags | 7;
  }
  return;
}

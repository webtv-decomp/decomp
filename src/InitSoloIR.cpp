void InitSoloIR(void)

{
  int GetManufacturer;
  
  _irSampleTail = 0;
  _irSampleHead = 0;
  SetSampleInterval(0xf);
  _Ox04004024 = 10;
  _Ox0400402c = 0x3083;
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

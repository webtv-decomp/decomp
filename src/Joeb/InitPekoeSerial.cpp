void InitPekoeSerial(void)

{
  InitWTVPort();
  0xa4f00000 = 0x3c;
  0xa4f00004 = 0;
  0xa4f0000c = 3;
  0xa4f00010 = 3;
  0xa4f00008 = 1;
  return;
}

void InitAudio(void)

{
  if (_gAudioBuf0 == 0) {
    AllocateAudioBuffers();
  }
  _gCurrentAudioBuf = _gAudioBuf0;
  InitAudioCodec();
  _DAT_a4002018 = 0;
  _DAT_a4002014 = 0x800;
  InitAudioClock();
  RegisterIntHandler(0x13,audioInterruptHandler,0,0);
  InitAudioInput();
  return;
}

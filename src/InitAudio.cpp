void InitAudio(void)

{
  if (_gAudioBuf0 == 0) {
    AllocateAudioBuffers();
  }
  _gCurrentAudioBuf = _gAudioBuf0;
  InitAudioCodec();
  AUD_ONCONFIG = 0;
  AUD_ONSIZE = 0x800;
  InitAudioClock();
  RegisterIntHandler(0x13,audioInterruptHandler,0,0);
  InitAudioInput();
  return;
}

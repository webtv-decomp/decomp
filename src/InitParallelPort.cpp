int InitParallelPort(void)

{
  int syschiprevision;
  ParallelDriver _gParallelDriver;
  int BoxParallelHWIntf;
  int SoloParallelHWIntf;
  
  syschiprevision = SystemChipRevision();
  if (syschiprevision == 0) {
    ParallelDriver = __builtin_new(0x10);
    BoxParallelHWIntf = (int *)BoxParallelHWIntf::BoxParallelHWIntf(ParallelDriver);
  }
  else {
    ParallelDriver = __builtin_new(0xc);
    BoxParallelHWIntf = (int *)SoloParallelHWIntf::SoloParallelHWIntf(ParallelDriver);
  }
  syschiprevision = (**(code **)(*BoxParallelHWIntf + 0x14))((int)BoxParallelHWIntf + (int)*(short *)(BoxParallelHWIntf + 0x10));
  SoloParallelHWIntf = 0;
  if (syschiprevision == 0) {
    _gParallelDriver = __builtin_new(0x1c);
    _gParallelDriver = ParallelDriver::ParallelDriver(_gParallelDriver,BoxParallelHWIntf);
    SoloParallelHWIntf = 1;
    if (_gParallelDriver == 0) {
      __builtin_delete(BoxParallelHWIntf);
      SoloParallelHWIntf = 0;
    }
  }
  return SoloParallelHWIntf;
}

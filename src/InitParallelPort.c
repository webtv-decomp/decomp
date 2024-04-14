int InitParallelPort(void)

{
  int syschiprevision;
  ParallelDriver _gParallelDriver;
  int *piVar3;
  int iVar4;
  
  syschiprevision = SystemChipRevision();
  if (syschiprevision == 0) {
    ParallelDriver = __builtin_new(0x10);
    piVar3 = (int *)BoxParallelHWIntf::BoxParallelHWIntf(ParallelDriver);
  }
  else {
    ParallelDriver = __builtin_new(0xc);
    piVar3 = (int *)SoloParallelHWIntf::SoloParallelHWIntf(ParallelDriver);
  }
  syschiprevision = (**(code **)(*piVar3 + 0x14))((int)piVar3 + (int)*(short *)(*piVar3 + 0x10));
  iVar4 = 0;
  if (syschiprevision == 0) {
    _gParallelDriver = __builtin_new(0x1c);
    _gParallelDriver = ParallelDriver::ParallelDriver(_gParallelDriver,piVar3);
    iVar4 = 1;
    if (_gParallelDriver == 0) {
      __builtin_delete(piVar3);
      iVar4 = 0;
    }
  }
  return iVar4;
}

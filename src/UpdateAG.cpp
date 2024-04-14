void InitExceptions(void)

{
  _SystemExceptionHook = &otherException;
  _CacheExceptionHook = &ParityException;
  _SystemIntHook = &CIntDecoder;
  move_exc_code();
  _gRegSave = &except_regs;
  SetSR(0x34000000);
  InstallDefaultIntHandlers();
  FlushAndInvalAllCaches();
  return;
}

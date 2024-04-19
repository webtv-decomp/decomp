void CreateIRTask(void)

{
  _gIRSignal = CreateSignal();
  _gIRTask = CreateTask(InterpretIRSamplesTask,0x1000,100,s_IRTask_805bc4d8,0);
  RegisterIntHandler(0x1d,C_IRIntHandler,0,0);
  DrainIRInFIFO();
  EnableInterrupt(0x1d);
  return;
}

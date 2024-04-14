#ifndef MAIN_H
#define MAIN_H

// Function declarations
int SizeMem();
int DetermineBootType();
void InitExceptions();
void InitHeap();
void InitializeMemoryManagement();
void InitIICIntf();
void CrashCounter();
void InitializeFilesystems();
void InitCrashLog();
void SetROMTiming();
void InitSiliconSerialNumber();
void DeviceManager__ProbeExpansionBus();
void InitDebugIO();
void InitRIO();
void InitWTVPort();
void InitAudio();
int FetchCounter();
void SetCompare(int value);
void enable_cpu_ints(int value);
void SetPowerLEDState(int state);
void InitParallelPort();
void InitDisk();
void NVErase();
void InitIR();
void InitTuner();
void Watchdog(int value);
void NVInit(int value);
void ProtectMemory();
void LateBoot();

#endif

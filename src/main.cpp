#include "include/webtv.h"

int main(int param_1,undefined *param_2,undefined4 param_3,int *param_4)

{
    uint **in_v0;
    int syschiprevision;
    int ParallelDriver;

    SizeMem();
    DetermineBootType();
    InitExceptions();
    InitHeap();
    InitializeMemoryManagement();
    InitIICIntf();
    CrashCounter();
    InitializeFilesystems();
    __builtin_new(0x70);
    _gVideoDriver = in_v0;
    VideoDriver__Init((char *)in_v0);
    InitCrashLog();
    SetROMTiming();
    InitSiliconSerialNumber();
    __builtin_new(4);
    DeviceManager__DeviceManager(in_v0);
    _gDeviceManager = in_v0;
    DeviceManager__ProbeExpansionBus(in_v0);
    InitDebugIO();
    InitRIO();
    InitWTVPort();
    InitAudio();
    iVar1 = FetchCounter();
    SetCompare(iVar1 + _DAT_8000028c * 10000);
    enable_cpu_ints(0xc400);
    SetPowerLEDState(2);
    InitParallelPort();
    InitDisk();
    if (gEraseNVSoon != '\0') {
        NVErase();
    }
    InitIR();
    InitTuner();
    _DAT_a4000030 = 0x69;
    Watchdog('\x01');
    uVar2 = 1;
    NVInit(1);
    ProtectMemory();
    LateBoot(uVar2,param_2,param_3,param_4);
    return 0;
}

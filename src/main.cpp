#include "include/webtv.h"

int main(void)

{
    DeviceManager _gDeviceManager;
    int counter;

    SizeMem();
    DetermineBootType();
    InitExceptions();
    InitHeap();
    InitializeMemoryManagement();
    InitIICIntf();
    CrashCounter();
    InitializeFilesystems();
    _gVideoDriver = DeviceManager(0x70);
    VideoDriver::Init();
    InitCrashLog();
    SetROMTiming();
    InitSiliconSerialNumber();
    _gDeviceManager = new DeviceManager();
    DeviceManager__ProbeExpansionBus();
    InitDebugIO();
    InitRIO();
    InitWTVPort();
    InitAudio();
    counter = FetchCounter();
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
    _BUS_WDVALUE = 0x69;
    Watchdog(1);
    NVInit(1);
    ProtectMemory();
    LateBoot();
    return 0;
}

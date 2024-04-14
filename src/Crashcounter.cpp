void CrashCounter(void)
{
    byte CrashCounter;
    char NVFlag;
    char NewCrashCounter;

    CrashCounter = ReadCrashCount();

    if (CrashCounter > 7) {
        CrashCounter = 0;
    }

    NewCrashCounter = CrashCounter + 1;

    if (NewCrashCounter == '\x04') {
        gEraseNVSoon = 1;
    }

    if (NewCrashCounter == '\x06') {
        WriteCrashCount(6);
        InvalidateMaxiBrowser();
        Watchdog(1);
        return;  // Exit the function after performing the actions
    }

    if (cVar3 == '\b') {
        WriteCrashCount(0);
        InvalidateMaxiBrowser();
        SetNVFlag(1, 0x14);
        Watchdog(1);
        return;  // Exit the function after performing the actions
    }

    NVRead = GetNVFlag(0x10);

    if (NVFlag != '\0') {
        SetNVFlag(0, 0x10);
    }

    WriteCrashCount(NewCrashCounter;
}

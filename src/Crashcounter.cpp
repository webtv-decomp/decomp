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
        // is a bad NVRAM value causing the crashes?
        gEraseNVSoon = 1;
    }

    if (NewCrashCounter == '\x06') {
        // most likely MaxiBrowser is hosed; invalidate and go to MiniBrowser (Logs it in Serial console on debug buildss)
        WriteCrashCount(6);
        InvalidateMaxiBrowser();
        Watchdog(1);
        return;
    }

    if (NewCrashCounter == '\b') {
        WriteCrashCount(0);
        // Good news your box hasnt crashed
        InvalidateMaxiBrowser();
        // Ryder: code looks like it sets counter to 0 meaning it hasnt crashed but It goes to Minibrowser (Memory address 0x80200000) because the MaxiBrowser (Approm) has been disabled for that startup (Logs it in Serial console on debug buildss)
        SetNVFlag(1, 0x14);
        // Sets NVFlag to 10 afer
        Watchdog(1);
        // Activate Watchdog
        return;
    }

    NVRead = GetNVFlag(0x10);

    if (NVFlag != '\0') {
        SetNVFlag(0, 0x10);
    }

    WriteCrashCount(NewCrashCounter);
}

void InitGFXTelevision(void) {
    TaskID tvTaskID = CreateTask(TVTask, 0x2000, 0x1065, "TVTask", 0);
    CreateTaskMessageQueue(tvTaskID, 4);
    TVTask = tvTaskID;
    TVMessageSig = CreateSignal();
}

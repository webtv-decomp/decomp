void JSAnchorArrayMethod___operator_array_integer_
(uint **param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
    uint uVar1;
    int *piVar2;
    uint uVar3;
    undefined8 uVar4;

    uVar3 = param_2;
    uVar1 = JSAnchorArrayMethod__length(param_1);
    uVar1 = (uint)(param_2 < uVar1);
    if (uVar1 == 0) {
        uVar4 = JSError__Report(1,uVar3,param_3,param_4);
        uVar1 = (uint)((ulonglong)uVar4 >> 0x20);
    }
    FindDocument(param_1);
    piVar2 = FrameDocument__GetAnchor(uVar1,param_2);
    JSArrayMethod__MakeInstance((uint)piVar2,&DAT_805996d4,param_3,param_4);
    return;
}



void JSAnchorArrayMethod___operator_array_string_(uint **param_1,int param_2)

{
    int in_v0;
    int *piVar1;
    undefined4 uVar2;
    undefined4 uVar3;

    FindDocument(param_1);
    uVar2 = 0;
    uVar3 = 0;
    piVar1 = FrameDocument__FindLink(in_v0,*(char **)(param_2 + 4),0,0);
    JSArrayMethod__MakeInstance((uint)piVar1,&DAT_805996d4,uVar2,uVar3);
    return;
}



undefined4 JSAnchorArrayMethod__length(uint **param_1)

{
    int in_v0;

    FindDocument(param_1);
    return *(undefined4 *)(in_v0 + 0xf4);
}



void JSAppletArrayMethod___operator_array_integer_
(uint **param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
    uint in_v0;
    uint uVar1;

    uVar1 = param_2;
    JSAppletArrayMethod__length(param_1);
    if (in_v0 <= param_2) {
        JSError__Report(2,uVar1,param_3,param_4);
    }
    JSArrayMethod__Find(param_1,&DAT_80599710);
    uVar1 = FrameDocument__GetApplet();
    JSArrayMethod__MakeInstance(uVar1,s_applet_80599718,param_3,param_4);
    return;
}



void JSAppletArrayMethod___operator_array_string_
(uint **param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
    uint uVar1;

    JSArrayMethod__Find(param_1,&DAT_80599710);
    uVar1 = FrameDocument__FindApplet();
    JSArrayMethod__MakeInstance(uVar1,s_applet_80599718,param_3,param_4);
    return;
}



void JSAppletArrayMethod__length(uint **param_1)

{
    JSArrayMethod__Find(param_1,&DAT_80599710);
    FrameDocument__GetAppletCount();
    return;
}



void JSAppletMethod__name(uint **param_1)

{
    JSArrayMethod__Find(param_1,s_applet__80599720);
    JSString__New((char *)0x0);
    return;
}

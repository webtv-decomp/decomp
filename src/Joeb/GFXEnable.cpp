uint GFXEnable(void)

{
  /* _DAT_8001bac8 = 3; */
  GFX_CONTROL = GFX_CONTROL | 0x80;
  return GFX_CONTROL;
}

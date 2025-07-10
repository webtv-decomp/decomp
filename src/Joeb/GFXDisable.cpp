uint GFXDisable(void)

{
  GFX_CONTROL = GFX_CONTROL & 0xffffff7f;
  return GFX_CONTROL;
}

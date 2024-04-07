#include "code.h"
void T_free(int param_1)

{
  if (param_1 != 0) {
    (*_tsw_SWFree)();
  }
  return;
}



void T_strcpy(char *param_1,char *param_2)

{
  strcpy(param_1,param_2);
  return;
}



void T_strcmp(char *param_1,char *param_2)

{
  strcmp(param_1,param_2);
  return;
}



void T_strlen(char *param_1)

{
  strlen(param_1);
  return;
}



void T_time(undefined4 *param_1)

{
  undefined4 in_v0;
  
  tsw_time32();
  *param_1 = in_v0;
  return;
}


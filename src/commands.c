#include <string.h>
#include <stdio.h>
#include "commands.h"
#include <unistd.h>

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
   return -1;

  // TODO: Fill it!
  chdir(argv[1]);
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char buf[255];
  getcwd(buf,255);
  printf("%s\n",buf);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  if(argc==2&&!strcmp(argv[0],"cd"))
   return 1;
  else
   return 0;
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
  if(argc==1&&!strcmp(argv[0],"pwd"))
   return 1;
  else
   return 0;
}

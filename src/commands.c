#include <string.h>
#include <stdio.h>
#include "commands.h"
#include <unistd.h>

int do_cd(int argc, char** argv) {
  if (!validate_cd_argv(argc, argv))
   return -1;

  // TODO: Fill it!
  int tmp=chdir(argv[1]);
  //int chdir(const char* path) : change current directory
  if(tmp==-1){
   fprintf(stderr,"bash: cd: %s: No such file or directory\n",argv[1]);
  return 0;
  }
  else if(tmp==0){
   return 0;
  }
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char buf[255];
  getcwd(buf,255);
  //char *getcwd(char *buf, size_t size) : get current directory
  printf("%s\n",buf);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {
  // TODO: Fill it!
  if(argc==2&&!strcmp(argv[0],"cd"))
   return 1;
  else if(argc==1&&!strcmp(argv[0],"cd")){
  // If you only type 'cd', this command is not supported by this program!
   return 0;
  }
  else
   // argc>2 -> Entered too much!
   return 0;  
}

int validate_pwd_argv(int argc, char** argv) {
  // TODO: Fill it!
  if(argc==1&&!strcmp(argv[0],"pwd"))
   return 1;
  else
  // This program is not supported pwd + any command!
   return 0;
}

#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  // TODO: Fill this!
 *argc=0;
 char* command_tmp=(char*)malloc(sizeof(char)*100);

 strcpy(command_tmp,command);

 for(int i=0;command_tmp[i]!='\0';i++){
  if(command_tmp[i]=='\n')
   command_tmp[i]==NULL;
 }

 char* token;
 token=strtok(command_tmp," \t\n");

 *argv=(char**)malloc(sizeof(char*)*100);

 if(token==NULL){
  (*argc)++;
  *(*argv)=(char*)malloc(sizeof(char)*100);
  strcpy(*(*argv),"");
 }

 while(token!=NULL){
  *(*argv+(*argc))=(char*)malloc(sizeof(char)*100);
  strcpy(*(*argv+(*argc)),token);
  token=strtok(NULL," \t\n");
  (*argc)++;
 }
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>



int check_param(char filein[],char fileout[]){
  if(filein==NULL||fileout==NULL){
   open("filestat.in",O_CREAT, 777);
   open("filestat.db",O_CREAT, 777);
   return 0;
  }
   else{
     return 1;
   }
}

//

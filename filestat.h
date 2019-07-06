#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>

#include "global.h"


/* #define Statements */
#define BUFFER_SIZE 100000
#define NAME_SIZE 12
#define MAX_LINES 100000
#define FILEINPUT "filestat.in"
#define FILEOUT "filestat.db"
#define PERM 755

/* Globals */
char *fileName = NULL; /* Points to file name */
char *fileOut = NULL;  /* Points to output file */
char *fileIn = NULL;  /* First option in program */
char *filePath [BUFFER_SIZE];  /* Path read from input file */
char tmpName [NAME_SIZE];
const char *buffer = NULL;

int lineCount = 0; /* Total number of lines in input */
int lineStart [MAX_LINES]; /* Store offsets of each line */
int fileOffset = 0; /* Current position in input */

int recoursive = 0; /* r mode on file activated flag */
int option_index = 0;
int fd;
mode_t mode = O_WRONLY|O_TRUNC; /*Mode only for write*/
mode_t readmode = O_RDONLY;




int
init_param(){
  int fd = open(FILEINPUT,O_RDWR);

  if(fd) return fd;
  else return -1;
}



int
openf(const char fname[],mode_t mode){

  int fd = open(fname,mode);
   if(fd == -1){
       return -1;
     }
   else{
       return fd;
   }

}//openf



int
creat_stdfile(void){
  int fd;
  fd = creat("filestat.in",mode);
  if(fd==-1){
    exit(EXIT_FAILURE);
  }
  else  {
    return fd;
  }
}



int
f_open(void) {
  int fd;
  printf("%s","opening file...\n");
  fd = openf(fileIn,readmode);
  return fd;
}




void
trackLines (char *buffer, int charsRead) {
  /* Store offsets of each line start in buffer */
  int i;
  for (i = 0; i < charsRead; i++) {
     ++fileOffset; /* Update current file position */
     if (buffer[i] == '\n') lineStart[++lineCount] = fileOffset; // Put line per line in a block of linestart
  }
}

char *
f_read(int fd){
char *buffer = malloc(BUFFER_SIZE);
char i = 0;
int l = 0;
ssize_t charsRead = 0;
size_t nbytes = sizeof(filePath);
char line[][];

   if(verbose==1) {
   printf("Reading file...\n");
   printf("%zu bytes\n", nbytes);
   }

  while(1){
  charsRead = read(fd,&i,sizeof (char) * 2 );
  if (charsRead == 0) break; /*End of file*/
   if (charsRead == -1){
     printf("errore\n");
     strerror(errno);
     break;
   }
   buffer[l++] = i;
   trackLines (buffer, charsRead); /* Process line */
  }
  lineStart[lineCount] = fileOffset;
  return buffer;
}







//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/mman.h>
#include <fnmatch.h>
#include <stddef.h>
#include <wchar.h>

#include "global.h"



/* #define Statements */
#define BUFFER_SIZE 100000
#define NAME_SIZE 12
#define MAX_LINES 100000
#define FILEINPUT "filestat.in"
#define FILEOUT "filestat.db"
#define PERM 755

/* Globals */

typedef struct path{
  char *path;
  char *option;
}path;



char *fileName = NULL; /* Points to file name */
char *fileOut = NULL;  /* Points to output file */
char *fileIn = NULL;  /* First option in program */
char *filePath [BUFFER_SIZE];  /* Path read from input file */
char tmpName [NAME_SIZE];
const char *buffer = NULL;
char **app = NULL;
int lineCount = 0; /* Total number of lines in input */
int lineStart [MAX_LINES]; /* Store offsets of each line */
int fileOffset = 0; /* Current position in input */
path inputData[MAX_LINES];
int i=0;

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


int
line_manage(char *line){

  char *string;
  char *tok;

  // set up the input, like this to show use of `strdup` and `free`
  string = strdup(line);       // allocate memory for source string
  if (string == NULL)                     // check it worked
      return 1;                           // failure

  // student name
  tok = strtok(string, " ");              // isolate first token
  if (tok == NULL)                        // check it worked
      return 1;                           // failure
  inputData[i].path = strdup(tok);         // allocated mem for substring and copy
  /*printf("path: %s\n", inputData[i].path);*/
  if (inputData[i].path == NULL)               // check it worked
      return 1;                           // failure


  // student number
  tok = strtok(NULL, " ");                // isolate next token
  if (tok == NULL)                        // check it worked
      return 1;                           // failure
  inputData[i].option = strdup(tok);      // extract int
  /*printf("option: %s\n", inputData[i].option);*/
      return 1;                           // failure


  i++;

  free(string);                           // can now get rid of source data
  free(line);
  free(inputData);

}


/*
void
lines_number(FILE *stream){
  size_t nread;
  char *line = NULL;
  size_t len = 0;


  while ((nread = getline(&line, &len, stream)) != -1) {
     lines++;
 }


}
*/

void
get_lines(FILE *stream){
  size_t nread = 0;
  char *line = NULL;
  size_t len = 0;

  //lines_number(stream);

  while ((nread = getline(&line, &len, stream)) != -1) {
              /*printf("%s\n",line);*/
              line_manage(line);
              lines++;
          }

   free(line);
   fclose(stream);
}


char *
f_read(int fd){
char *buffer = malloc(BUFFER_SIZE);
char i = 0;
int l = 0;
ssize_t charsRead = 0;
size_t nbytes = sizeof(filePath);

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
  }
  lineStart[lineCount] = fileOffset;
  return buffer;
}








//




































//

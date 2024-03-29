#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <getopt.h>
#include <fnmatch.h>


#include "stat.h"
#include "filestat.h"
#include "options.h"

/* Prototypes */
void optionsManage(int argc, char const *argv[]);
FILE * fdopen (int filedes, const char *opentype);
/*--------------------*/

/* Global */
static struct
   option long_options[] = {
    {"verbose",no_argument, 0, 0 },
    {"stat"   ,no_argument, 0, 0 },
    {"report" ,no_argument, 0, 0 },
    {"history",required_argument, 0, 0},
    {"user",  required_argument,  0, 0},
    {"group", required_argument,  0, 0},
    {"length",required_argument,  0, 0},
    {"manual",no_argument,  0, 0},
    {"noscan",no_argument,0,0}
};


void
fatalError(void){
  perror("filestat  ");
  exit(1);
}


void
usage (int status)
{
      printf (("\
Usage: %s [OPTION]... [INPUT FILE]... [OUTPUT FILE]...\n\
"),
         "filestat");
      fputs (("\
  -v, --verbose          output a diagnostic for every file processed\n\
  -s, --stat             output\n\
"), stdout);
      fputs (("\
  -h\n\
  -u\n\
"), stdout);
      fputs (("\
  -g\n\
"), stdout);
      fputs (("\
  -l\n\
"), stdout);
      fputs (("\
\n\
  -n \n\
"), stdout);

  exit (status);
}


int
main(int argc, char **argv) {

  int c;
  int param_ok = 0;
  FILE * pf = NULL;

  printf("%d",argc);


  if(argc<4){
     usage(EXIT_FAILURE);
  }


  fileIn = argv[2];  //[2]
  fileOut = argv[3]; // [3]

  printf("params: \n");
  printf("\%s\n" "%s\n"
  ,fileIn,fileOut);

  param_ok = check_param(fileIn,fileOut);

  if(param_ok == 1) {
  int filedes = f_open();
  printf("file %s open\n",fileIn);
  //buffer =  f_read(filedes);
  pf = fdopen(filedes,"rw");
  get_lines(pf);
  fflush(pf);
  //readfile(filedes,filePath,BUFFER_SIZE);
}

//  int fnmatch (const char *pattern, const char *string, int flags)

//matchResult = fnmatch(pattern,buffer,FNM_FILE_NAME);


 while (1) {

     c = getopt_long(argc, argv, "vsmrh:u:g:l:",
               long_options, &option_index);
      if (c == -1)
          break;

     switch (c) {

     case 'v':
          verbose = 1;
          break;

     case 's':
          statistic = 1;
          break;

     case 'r':
          report = 1;
          break;

     case 'h':
          history = 1;
          break;

     case 'u':
          user = 1;
           break;

     case 'g':
          group = 1;
           break;

     case 'l':
         length = 1;
          break;

      case 'm':
         usage(EXIT_SUCCESS);
          break;

     default:
         usage (EXIT_FAILURE);
      }
  }



  if(statistic){
    int i=0;
    for(i=0;i<lines;i++){
      file_stat(inputData[i].path);
      }
    }




 exit(EXIT_SUCCESS);


  return 0;
}














//

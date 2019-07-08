#include <stdio.h>
#include <stdlib.h>
#include <string.h>



/*Filestat variables*/
const char *pattern = "\n";
int lines = 0;

path inputData[lines];



/*Parameters variables*/
int verbose = 0;
int statistic = 0;
int report = 0;
int history = 0;
int user = 0;
int group = 0;
int length = 0;
int noscan = 0;


/*
void
lines_number(const char *buffer,int size){
  int res = 0;
  int i=0;

  while(i<size){
    if((res = fnmatch(pattern,&buffer[i],FNM_NOESCAPE) ) == 0 ){  lines++; i++; }
     else i++;
 }
}
*/

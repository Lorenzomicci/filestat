#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


/*Global variables (options)*/
int f_verbose;           // During execution see information on file and data
int f_stat;              // Are shown on the standard output the following statistics: number of monitored files; number of links; directory number; total size; average size; maximum size; minimum size (in bytes).
int f_report;           // ...
int f_history;
int f_user;
int f_group;
int f_length;
int f_noscan;


const char *filename = NULL;
int fd;

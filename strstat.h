#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


typedef struct char splitFile{
  char *string [] [];
}


const char delimiter = " ";
char *token;
char *cp;

cp = strdupa(buffer); /*Make writable copy of buffer*/

token = strtok (cp, delimiters);

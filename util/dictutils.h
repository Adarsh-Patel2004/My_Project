#ifndef DICTUTILS_H
#define DICTUTILS_H

#include "dicttype.h"

char *addbefore(dict *D, char *S);
char *addafter(dict *D, char *S);
char **anagrams(dict *D, char *S);

#endif

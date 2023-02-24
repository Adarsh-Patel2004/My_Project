#ifndef DICTLOAD_H
#define DICTLOAD_H

#include "trie.h"
#include "dicttype.h"

#define DFLT_DICT "dict/words.txt"

// Loads the default dictionary (words.txt) into a dict
dict *loaddfltdict();

// Loads a dictionary from the specified file into a dict
dict *loaddict(const char *fname);

#endif

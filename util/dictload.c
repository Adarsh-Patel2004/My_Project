#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dicttype.h"
#include "dictload.h"

#define DFLT_DICT "dict/words.txt"

dict* loaddfltdict() {
    dict* d = trie_new();
    FILE* fp = fopen(DFLT_DICT, "r");
    if (!fp) {
        fprintf(stderr, "Error opening %s\n", DFLT_DICT);
        exit(EXIT_FAILURE);
    }
    char word[100];
    while (fgets(word, sizeof(word), fp)) {
        word[strlen(word) - 1] = '\0';
        trie_insert(d, word);
    }
    fclose(fp);
    return d;
}

dict* loaddict(const char* fname) {
    dict* d = trie_new();
    FILE* fp = fopen(fname, "r");
    if (!fp) {
        fprintf(stderr, "Error opening %s\n", fname);
        exit(EXIT_FAILURE);
    }
    char word[100];
    while (fgets(word, sizeof(word), fp)) {
        word[strlen(word) - 1] = '\0';
        trie_insert(d, word);
    }
    fclose(fp);
    return d;
}

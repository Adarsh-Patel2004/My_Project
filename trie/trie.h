#ifndef TRIE_H
#define TRIE_H

#define MAX_WORD_LENGTH 50
#define MAX_ALPHABET_SIZE 26

typedef struct trienode
{
    char label;
    int end_of_word;
    struct trienode *first_child;
    struct trienode *next_sibling;
} trienode;

typedef struct trie
{
    trienode *root;
} trie;

trie *trieinit();
int triesearch(trie *t, char *s);
void trieinsert(trie *t, char *s);
void listall(trie *t);
void listall_recursive(trienode *curr, char *word, int word_index);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictutils.h"
#include "trie.h"

char *addbefore(dict *D, char *S) {
    int i, j;
    char c, *before = malloc(26 * sizeof(char));
    trie *t = D->root;

    for (i = 0; i < 26; i++) {
        c = 'a' + i;
        for (j = strlen(S); j >= 0; j--) {
            S[j + 1] = S[j];
        }
        S[0] = c;
        if (search(t, S)) {
            before[i] = c;
        } else {
            before[i] = '\0';
        }
    }

    return before;
}

char *addafter(dict *D, char *S) {
    int i, j, len;
    char c, *after = malloc(26 * sizeof(char));
    trie *t = D->root;
    len = strlen(S);

    for (i = 0; i < 26; i++) {
        c = 'a' + i;
        S[len] = c;
        S[len + 1] = '\0';
        if (search(t, S)) {
            after[i] = c;
        } else {
            after[i] = '\0';
        }
    }

    return after;
}

char **anagrams(dict *D, char *S) {
    int i, j, k, len, count = 0;
    char *temp, **anagrams;
    trie *t = D->root;
    len = strlen(S);

    for (i = 0; i < len; i++) {
        for (j = i; j < len; j++) {
            if (S[i] > S[j]) {
                temp = S[i];
                S[i] = S[j];
                S[j] = temp;
            }
        }
    }

    do {
        if (search(t, S)) {
            count++;
        }
    } while (next_permutation(S, len));

    anagrams = (char **)malloc((count + 1) * sizeof(char *));
    count = 0;
    do {
        if (search(t, S)) {
            anagrams[count] = (char *)malloc((len + 1) * sizeof(char));
            strcpy(anagrams[count], S);
            count++;
        }
    } while (next_permutation(S, len));
    anagrams[count] = NULL;

    return anagrams;
}

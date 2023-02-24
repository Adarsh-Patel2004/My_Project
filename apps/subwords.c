#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordutils.h"

void freedict(dict *dict);

int main() {
    dict *dict = loaddict("words.txt");
    if (!dict) {
        fprintf(stderr, "Failed to load default dictionary\n");
        return 1;
    }

    char word[256];
    printf("Enter a word: ");
    scanf("%s", word);

    char **anagram = anagrams(dict, word);
    int count = 0;
    for (int i = 0; anagram[i]; i++) {
        printf("%s\n", anagram[i]);
        count++;
    }

    printf("%d subwords found\n", count);

    for (int i = 0; i < count; i++) {
        free(anagram[i]);
    }
    free(anagram);
    freedict(dict);

    return 0;
}

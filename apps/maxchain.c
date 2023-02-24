#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wordutils.h"

void freedict(dict *dict);

// Recursive function to find the longest chain of valid words
void findLongestChain(dict *dict, char *word, int level, int *maxlevel, char **longestchain)
{
    // Add a letter to the beginning of the word
    char *before = addbefore(dict, word);
    if (before != NULL)
    {
        // Update the chain of words and the current level
        longestchain[level] = before;
        if (level > *maxlevel)
        {
            *maxlevel = level;
        }
        findLongestChain(dict, before, level + 1, maxlevel, longestchain);
    }

    // Add a letter to the end of the word
    char *after = addafter(dict, word);
    if (after != NULL)
    {
        // Update the chain of words and the current level
        longestchain[level] = after;
        if (level > *maxlevel)
        {
            *maxlevel = level;
        }
        findLongestChain(dict, after, level + 1, maxlevel, longestchain);
    }
}

int main()
{
    // Load the dictionary
    dict *dict = loaddict("words.txt");
    if (dict == NULL)
    {
        printf("Error: Could not load the dictionary\n");
        return 1;
    }

    char *word = "a";
    char *longestchain[1000];
    int maxlevel = 0;

    // Find the longest chain of valid words
    findLongestChain(dict, word, 0, &maxlevel, longestchain);

    // Print the longest chain of words
    printf("%s\n", word);
    for (int i = 0; i <= maxlevel; i++)
    {
        printf("==> %s\n", longestchain[i]);
    }

    freedict(dict);
    return 0;
}

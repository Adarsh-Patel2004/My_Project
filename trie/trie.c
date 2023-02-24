#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

trie *trieinit()
{
    trie *t = (trie *)malloc(sizeof(trie));
    trienode *root = (trienode *)malloc(sizeof(trienode));

    root->label = '-';
    root->end_of_word = 0;
    root->first_child = NULL;
    root->next_sibling = NULL;

    t->root = root;
    return t;
}

int triesearch(trie *t, char *s)
{
    trienode *p = t->root;
    int n = strlen(s);

    for (int i = 0; i < n; i++)
    {
        int j;
        trienode *c = p->first_child;

        for (j = 0; j < MAX_ALPHABET_SIZE; j++)
        {
            if (c == NULL)
                break;

            if (c->label == s[i])
            {
                p = c;
                break;
            }
            c = c->next_sibling;
        }

        if (j == MAX_ALPHABET_SIZE)
            return 0;
    }

    return (p->end_of_word);
}

// Function to insert a string in the trie
void trieinsert(trie *t, char *s)
{
    int i = 0, len = strlen(s);
    trienode *curr = t->root;
    trienode *temp;

    while (i < len)
    {
        // Check if there is a child node with the same character
        temp = curr->first_child;
        while (temp != NULL && temp->label < s[i])
            temp = temp->next_sibling;

        // If there is no child node with the same character, insert a new node
        if (temp == NULL || temp->label > s[i])
        {
            trienode *new_node = (trienode *) malloc(sizeof(trienode));
            new_node->label = s[i];
            new_node->end_of_word = 0;
            new_node->first_child = NULL;

            // Insert the new node in the list of children, keeping it sorted
            if (curr->first_child == NULL)
                curr->first_child = new_node;
            else
            {
                trienode *temp2 = curr->first_child;
                while (temp2->next_sibling != NULL && temp2->next_sibling->label < s[i])
                    temp2 = temp2->next_sibling;

                new_node->next_sibling = temp2->next_sibling;
                temp2->next_sibling = new_node;
            }
            curr = new_node;
        }
        // If there is a child node with the same character, move to that node
        else
            curr = temp;
        i++;
    }

    // Mark the last node as the end of a word
    curr->end_of_word = 1;
}

// Function to print all words stored in the trie
void listall(trie *t)
{
    trienode *curr = t->root->first_child;
    char word[MAX_WORD_LENGTH];
    int word_index = 0;

    listall_recursive(curr, word, word_index);
}

// Recursive function to print all words stored in the trie
void listall_recursive(trienode *curr, char *word, int word_index)
{
    if (curr == NULL)
        return;

    word[word_index] = curr->label;
    if (curr->end_of_word)
    {
        word[word_index + 1] = '\0';
        printf("%s\n", word);
    }
    listall_recursive(curr->first_child, word, word_index + 1);
    listall_recursive(curr->next_sibling, word, word_index);
}


#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose a larger N for faster performance (fewer collisions)
// 2^16 is a good balance between memory and speed
const unsigned int N = 65536;

// Hash table
node *table[N];

// Global variable to track dictionary size
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash the word to get the index
    unsigned int index = hash(word);

    // Access the linked list at that index
    node *cursor = table[index];

    // Traverse the linked list
    while (cursor != NULL)
    {
        // Use strcasecmp for case-insensitive comparison
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
// This is a variation of the djb2 hash function (very fast for strings)
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = tolower(*word++)))
    {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Buffer for the word
    char word[LENGTH + 1];

    // Read each word from the file
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for each word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }

        // Copy word into node
        strcpy(new_node->word, word);

        // Hash word to find index
        unsigned int index = hash(word);

        // Insert node into hash table (at the head of the list)
        new_node->next = table[index];
        table[index] = new_node;

        // Increment the global word counter
        word_count++;
    }

    // Close the file
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        // Traverse the linked list and free nodes
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        // Safety check: point bucket back to NULL
        if (i == N - 1 && cursor == NULL)
        {
            return true;
        }
    }
    return false;
}

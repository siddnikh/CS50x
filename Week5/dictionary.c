// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//number of words
int number = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    node *ptr = table[hash(word)];

    if(strcasecmp(ptr -> word, word) == 0){
        return true;
    }

    while(ptr -> next != NULL){
        ptr = ptr -> next;
        if(strcasecmp(ptr -> word, word) == 0){
            return true;
        }
    }

    return false;
}


// Hashes word to a number
unsigned int hash(const char *word)
{
    return (toupper((int)word[0]) - 65);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //opening file
    FILE *file = fopen(dictionary, "r");

    if(file == NULL){
        printf("File can't be opened");
        return false;
    }

    char *word = malloc(LENGTH);
    if(word == NULL){
        printf("Unable to allocate memory for word");
        return false;
    }

    while(fscanf(file, "%s", word) != EOF){

        //allocating memory for a node
        node *n = malloc(sizeof(node));

        //memory check
        if(n == NULL){
            printf("Unable to allocate memory");
            return false;
        }

        strcpy(n -> word, word);
        //inserting the node in our hash table
        n -> next = table[hash(word)];
        table[hash(word)]= n;

        number++;
    }
    fclose(file);
    free(word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return number;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *ptr;
    node *tmp;

    //iterating over the table
    for(int i = 0; i < N; i++){

        if(table[i] == NULL){
            continue;
        }

        ptr = table[i];
        tmp = ptr;

        while(ptr -> next != NULL){
            ptr = ptr -> next;
            free(tmp);
            tmp = ptr;
        }
        free(ptr);
    }

    return true;
}

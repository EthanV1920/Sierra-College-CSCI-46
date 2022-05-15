#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "md5.h"

const int PASS_LEN = 20;        // Maximum any password will be
const int HASH_LEN = 33;        // Length of MD5 hash strings

// Function prototypes
char * crackHash(char * targetHash, char * dictionaryFilename);
int wordCount(char *list, int size);
void entryPopulation(char **entryList, char *contents, int size);
void contentPopulation(char *contents, int size);

int main(int argc, char *argv[])
{
    crackHash(argv[1], argv[2]);
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Open the hash file for reading.
    

    // For each hash, crack it by passing it to crackHash
    
    // Display the hash along with the cracked password:
    //   5d41402abc4b2a76b9719d911017c592 hello
    
    // Close the hash file
    
    // Free up any malloc'd memory?
}

// Given a target hash, crack it. Return the matching password.
char * crackHash(char * targetHash, char * dictionaryFilename)
{
    // char *dictHash;
    // char *lineHash;
    // char dictBuf[HASH_LEN];
    // char lineBuf[HASH_LEN];

    // Open the target file
    struct stat target;
    stat(targetHash, &target);
    printf("FILE: %s    SIZE: %lld\n", targetHash, target.st_size);
    FILE *targetFile = fopen(targetHash, "r");
    if(!targetFile){
        char errorStr[100];
        sprintf(errorStr, "Can't open %s for reading: ", targetHash);
        perror(errorStr);
        exit(1);
    }

    char *targetContents = malloc(target.st_size);
    fread(targetContents, 1, target.st_size, targetFile);


    // Open the dictionary file and load in to memory
    struct stat dict;
    stat(dictionaryFilename, &dict);    
    printf("FILE: %s    SIZE: %lld\n", dictionaryFilename, dict.st_size);

    FILE *dictionaryFile = fopen(dictionaryFilename, "r");
    if(!dictionaryFile){
        char errorStr[100];
        sprintf(errorStr, "Can't open %s for reading: ", dictionaryFilename);
        perror(errorStr);
        exit(1);
    }

    char *dictionaryContents = malloc(dict.st_size);
    fread(dictionaryContents, 1, dict.st_size, dictionaryFile);

    // Loop through the dictionary file, one line at a time.
    
    int targetCount = wordCount(targetContents, target.st_size);
    int dictCount = wordCount(dictionaryContents, dict.st_size);

    printf ("TARGET WORDCOUNT: %d   DICTIONARY WORDCOUNT: %d\n", targetCount, dictCount);
    // char **targetEntries = malloc(wordCount(targetContents, target.st_size) * sizeof(char*));
    // char **dictEntries = malloc(wordCount(dictionaryContents, dict.st_size) * sizeof(char*));
    char **targetEntries = malloc(targetCount * sizeof(char*));
    char **dictEntries = malloc(dictCount * sizeof(char*));

    entryPopulation(targetEntries, targetContents, target.st_size);
    entryPopulation(dictEntries, dictionaryContents, dict.st_size);

    // dictHash = md5(dictEntries[1], strlen(dictEntries[1]));
    // printf("%d - %s\n",1, dictHash);
    // dictHash = md5(dictEntries[2], strlen(dictEntries[2]));
    // printf("%d - %s\n",2, dictHash);
    // dictHash = md5(dictEntries[3], strlen(dictEntries[3]));
    // printf("%d - %s\n",3, dictHash);
    // dictHash = md5(dictEntries[4], strlen(dictEntries[4]));
    // printf("%d - %s\n",4, dictHash);


    for(int i = 0; i < dictCount; i++){
        // printf("%s - %d\n", dictEntries[i], strlen(dictEntries[i]));
        char *dictHash = md5(dictEntries[i], strlen(dictEntries[i]));
        // printf("%d - %s\n> ",i, dictHash);
        for(int j = 0; j < targetCount; j++){
            if(strcmp(dictHash, targetEntries[j])==0){
                printf("FOUND: %s\n", dictEntries[i]);
            }
        }
    }

    printf("DONE");

    // while (fgets(dictBuf, 255, dictionaryFile) != NULL){
    //     *strchr(dictBuf, '\n') = '\0';
    //     dictHash = md5(dictBuf, strlen(dictBuf));
    //     printf("HASH: %s\n", dictHash);
    //     while (fgets(lineBuf, HASH_LEN, targetFile) != NULL){
    //         // *strchr(dictBuf, '\n') = '\0';
    //         // lineHash = md5(lineBuf, strlen(lineBuf));
    //         if(strcmp(lineBuf, dictHash)==0){8
    //             printf("FOUND: %s\n", dictHash);
    //         }
    //     }
        
    //     // fprintf(out, "%s\n", hash);
    // }

    // free(dictionaryContents);
    // Hash each password. Compare to the target hash.
    // If they match, return the corresponding password.
    
    // Close the dictionary file. Free up memory?

    return NULL;
}

int wordCount(char *list, int size){
    int count = 0;
    // *strchr(list, '\n') = '\0';

    for(int i = 0; i < size; i++){
        if(list[i]=='\n'){
            list[i] = '\0';
            count++;
        }
    }
    return count;
}

// void contentPopulation(char *contents, int size){
//     for(int i = 0; i < size; i++){

//     }

// }

void entryPopulation(char **entryList, char *contents, int size){
    int debug = 0;
    entryList[0] = &contents[0];
    if(debug == 1)printf("DEBUG: %d - %s\n", 0, entryList[0]);
    int entry = 1;

    for(int i = 1; i < size; i++){
        if(contents[i] == '\0'){
            entryList[entry] = &contents[i+1];
            if(debug == 1)printf("DEBUG: %d - %s\n", entry, entryList[entry]);
            entry++;
        }
    }
}
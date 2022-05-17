#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN=50;        // Maximum any password will be
const int HASH_LEN=33;        // MD5 Hash length


// Stucture to hold both a plaintext password and a hash.
struct entry 
{
    char password[PASS_LEN];
    char hash[33];
};

// Read in the dictionary file and return an array of entry structs.
// Each entry should contain both the hash and the dictionary word.
struct entry *read_dictionary(char *filename, int *size)
{
    char line[PASS_LEN+1];
	int capacity = 50;
	int entryCount = 0;
    int debug = 0;          // 0 for no debug - 1 for debug
    
    FILE *dict = fopen(filename, "r");
	if (!dict)
	{
        printf("Can't open file %s for reading: ", filename);
	    perror(NULL);
	    exit(1);
	}

    struct entry *dictContents = malloc(capacity * sizeof(struct entry));

    // Read in each line of the dictionary file
    while (fgets(line, PASS_LEN+1, dict) != NULL)
	{
		*strchr(line, '\n') = '\0';
		if(entryCount >= capacity){
			capacity+=50;
			dictContents = realloc(dictContents, capacity * sizeof(struct entry));
		}
		char *newStr = malloc((strlen(line)+1) * sizeof(char));
		if(debug)printf("Entry %d - %s\n", entryCount, line);
		strcpy(newStr, line);
		if(debug)printf("Entry %d - %s\n", entryCount, newStr);
		strcpy(dictContents[entryCount].password, newStr);
        strcpy(dictContents[entryCount].hash, md5(newStr, strlen(newStr)));
		entryCount++;
	}

    if(debug){
		for(int i = 0; i < entryCount; i++){
			printf("Entry %d - %s\n", i, dictContents[i].password);
		}
	}
	
    *size = entryCount;
    return dictContents;
}

int sortMethod(const void *a, const void *b){
    int cmp = strcmp(((struct entry *)a)->hash, ((struct entry *)b)->hash);
    // printf("CMP: %d", cmp);
    return cmp;
}

int searchMethod(const void *a, const void *b){
    char *aa = (char *)a;
    struct entry *bb = (struct entry *)b;
    // printf("strings: %s - %s\n", aa, bb->hash);
    int cmp = strcmp(aa, bb->hash);
    // printf("CMP: %d", cmp);
    return cmp;

}

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // Read the dictionary file into an array of entry structures
    int dictSize = 0;
    struct entry *dict = read_dictionary(argv[2], &dictSize);
    printf("Dict Count: %d\n", dictSize);

    // Open the hash file for reading.
    FILE *hashFile = fopen(argv[1], "r");
	if (!hashFile)
	{
        printf("Can't open file %s for reading: ", argv[1]);
	    perror(NULL);
	    exit(1);
	}

    // Sort the hashed dictionary using qsort by hash
    qsort(dict, dictSize, sizeof(struct entry), sortMethod);
    
    char line[HASH_LEN];
    while(fgets(line, HASH_LEN+1, hashFile)){
        *strchr(line, '\n') = '\0';
        printf("LINE: %s ", line);
        
        // For each hash, search for it in the dictionary using binary search.
        // Get the corresponding plaintext dictionary word.
        struct entry *found = bsearch(&line, dict, dictSize, sizeof(struct entry), searchMethod);
        
        // Print out both the hash and word.
        if(found){
            printf("FOUND: %s\n", found->password);
        }else{
            printf("Not Found\n");
        }
    }
    fclose(hashFile);
}

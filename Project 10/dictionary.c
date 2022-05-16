#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

// Load the dictionary of words from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadDictionary(char *filename, int *size)
{
	char line[255];
	int capacity = 5;
	int entryCount = 0;
	int debug = 0;

	FILE *dict = fopen(filename, "r");
	if (!dict)
	{
	    perror("Can't open dictionary");
	    exit(1);
	}
	
	// Allocate memory for an array of strings
	char **dictContents = malloc(capacity * sizeof(char*));

	// Read the dictionary line by line.
	// Expand array if necessary (realloc).
	// Allocate memory for the string (str).
	// Copy each line into the string (use strcpy).
	// Attach the string to the large array (assignment =).
	while (fgets(line, 255, dict) != NULL)
	{
		*strchr(line, '\n') = '\0';
		if(entryCount >= capacity){
			capacity+=5;
			dictContents = realloc(dictContents, capacity * sizeof(char*));
		}
		char *newStr = malloc((strlen(line)+1) * sizeof(char));
		if(debug)printf("Entry %d - %s\n", entryCount, line);
		strcpy(newStr, line);
		if(debug)printf("Entry %d - %s\n", entryCount, newStr);
		dictContents[entryCount] = newStr;
		entryCount++;
	}
	
	if(debug){
		for(int i = 0; i < entryCount; i++){
			printf("Entry %d - %s\n", i, dictContents[i]);
		}
	}
	
	// The size should be the number of entries in the array.
	*size = entryCount;
	if(debug)printf("Size PTR: %d\n", *size);

	// Return pointer to the array of strings.
	return dictContents;
}

// Search the dictionary for the target string
// Return the found string or NULL if not found.
char * searchDictionary(char *target, char **dictionary, int size)
{
    if (dictionary == NULL) return NULL;
    
	for (int i = 0; i < size; i++)
	{
	    if (strcmp(target, dictionary[i]) == 0)
	    {
	        return dictionary[i];
	    }
	}
	return NULL;
}
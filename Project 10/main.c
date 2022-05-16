#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"


int main(int argc, char *argv[])
{
	if (argc < 1)
	{
		fprintf(stderr, "Must supply a dictionary filename\n");
		exit(1);
	}
	
	int dlen;
	char **d = loadDictionary(argv[1], &dlen);
	
	printf("Dictionary loaded.\n");
	
	while(1)
	{
		char target[100];
		printf("Word to search for: ");
		fgets(target, 100, stdin);
		
		// Trim newline
		char *nl = strchr(target, '\n');
		if (nl) *nl = '\0';
		
		if (strcmp(target, "DONE") == 0) break;
		
		char *found = searchDictionary(target, d, dlen);
		if (found)
			printf("Found: %s\n", found);
		else
			printf("Not found!\n");
	}
}


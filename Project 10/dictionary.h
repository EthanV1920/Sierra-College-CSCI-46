// Load the dictionary of words from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadDictionary(char *filename, int *size);

// Search the dictionary for the target string
// Return the found string or NULL if not found.
char * searchDictionary(char *target, char **dictionary, int size);
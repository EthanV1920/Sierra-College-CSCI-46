// Ethan Vosburg
// May 11, 2022

// The program will accept two command line arguments:

//     The source file name to read plaintext from
//     The destination file name to write hashes to

// If the user doesn't supply these two filenames, an appropriate error
// message should be displayed and the program exits with status code 1.
// Each line in the source file is read in, hashed, and the hash written
// to the destination file. Each input line should have its newline, if
// present, trimmed off before hashing.

#include <stdio.h>
#include <string.h>
#include "md5.h"

int main(){
    printf("Please enter a string: ");
    char line[1000];
    fgets(line, 1000, stdin);

    // trim newline
    *strchr(line, '\n') = '\0';

    char *hash = md5(line, strlen(line));

    printf("HASH: %s\n", hash);
}
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
#include <stdlib.h>
#include <string.h>
#include "md5.h"

int main(int argc, char *argv[]){
    char line[255];
    int linecount = 0;
    char *hash;
    int showline = 0;

    // Open file for reading data
    FILE *in = fopen(argv[1], "r");
    if(!in){
        printf("Can't open %s for reading\n", argv[1]);
        perror(NULL);
        exit(1);
    }
    
    // Open/create file for new data
    FILE *out = fopen(argv[2], "w");
    if(!out){
        printf("Can't open %s for writing\n", argv[2]);
        perror(NULL);
        exit(1);
    }

    // check for verbose flag
    if(argv[3] && strcmp(argv[3], "-v")==0) {
        showline = 1;   
    }
    if(argv[3] && strcmp(argv[3], "-v")!=0) {
        printf("Unknown argument \"%s\"", argv[3]);
    }

    // Iterate over file contents and write hashes to out
    while (fgets(line, 255, in) != NULL){
        linecount++;
        *strchr(line, '\n') = '\0';
        hash = md5(line, strlen(line));
        if(showline==1) printf("HASH %d: %s\n", linecount, hash);
        fprintf(out, "%s\n", hash);
    }

    // Close files
    fclose(in);
    fclose(out);

}
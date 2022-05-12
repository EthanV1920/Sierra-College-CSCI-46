// Ethan Vosbrug
// May 10, 2022

// Write a program called filesearch that accepts two command line arguments:
//     A string
//     A filename

// If the user did not supply both arguments, the program should display an
// error message and exit. The program opens the given filename. Each line 
// that contains the given string is displayed. Use the strstr function to 
// search each line for the string. You may assume no line is longer than 255 
// characters.The matching lines are displayed to standard output.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *f = fopen(argv[1], "r");
    int linecount = 0;
    if(!f){
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }

    char line[255];
    while (fgets(line, 255, f) != NULL){
        linecount++;
        if(!argv[3] && strstr(line, argv[2])){
            *strchr(line, '\n') = '\0';
            printf("NOTE: Found \"%s\" on line %d\n      Line reads: %s\n", argv[2], linecount, line);
        }
        if(argv[3]){    
            if(strcmp(argv[3], "-i")==0 && strcasestr(line, argv[2])){
                *strchr(line, '\n') = '\0';
                printf("NOTE: Found \"%s\" on line %d\n      Line reads: %s\n", argv[2], linecount, line);
            }
        }
    }
    
}   
// Ethan Vosburg
// February 21st, 2022

// This program will be written in a file called flag.c. Prompt the
// user for the height of a flag pole. Acceptable values are 3 to 14, 
// inclusive. Then draw a flag blowing in the wind atop a flag pole 
// of that height. The flag is always 3 rows tall and 8 columns wide.
// In the example below, the flag pole is 8 rows high. The flag itself
// is 3 rows, leaving 5 for the pole alone.

#include <stdio.h>

int main(){

    int 
    pole_length,
    i;

    printf("\nLegth of pole: ");
    scanf("%d", &pole_length);

    if(pole_length <= 3 && pole_length >= -3){
        printf("Please enter a value that is not between -3 and 3\nexiting...");
    }else{
        if(pole_length > 0){
            printf("|------+\n|      |\n|------+\n");
            for (i = 0; i < pole_length-3; i= i+1){
                printf("|\n");
            }
        }else{
            for (i = 0; i > pole_length+3; i= i-1){
                printf("       |\n");
            }
            printf("+------|\n|      |\n+------|\n");
        }
    }

}
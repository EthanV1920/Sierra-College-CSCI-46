// Ethan Vosburg
// March 23, 2022

// In this assignment you will write a simple program to capitalize each word
// in a user-inputted string. Your program will have the following features:
//    -Prompt user to enter a string. The string may be up to 100 characters.
//    -A function to capitalize each word in the string.
//    -Display the capitalized string back to the user.

// Include libraries
#include <stdio.h>
#include <string.h>

// Print out array with attention to end character
void printArray(char array[], int length){
    int end = 0;
    int i = 0;

    while(end == 0){
      if(array[i] == 0){
            end = 1;
        }else{
            printf("%c", array[i]);
            i++;
        }
    }      
}


int main(){
    // Take in user input
    printf("\nPlease enter a string less than 100 characters: ");
    char usrInput[100];    
    fgets(usrInput, 100, stdin);

    // Check first character in sting for capitalization 
    if(usrInput[0] >= 'a' && usrInput[0] <= 'z'){
        usrInput[0] =  usrInput[0]-32;       
    }

    // Capitalize each character directly proceeding a space by adding 32 to the ascii value
    for(int i = 0; i <100; i ++){
        if(usrInput[i] >= 'a' && usrInput[i] <= 'z'){
            if(usrInput[i-1]==32){
                usrInput[i] =  usrInput[i]-32;
            }
        }
    }

    // Print final sting
    printf("\nHere is your string: ");
    printArray(usrInput, 100);

}
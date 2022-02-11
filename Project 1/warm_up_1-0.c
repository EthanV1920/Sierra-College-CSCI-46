// Ethan Vosburg
// Febuary 2nd 2021

// Write a program that prompts the user for the height and width of a 
// rectangle (in inches, as integers). It calculates the area of the 
// rectangle and displays it to the user.

// Library Importing
#include <stdio.h>

int main (){

    printf("\nGiven the user input of width and height\narea will be returned in sq in.\n\n");

    // declare variables
    int height, width, area;

    // accept user input
    printf("height: ");
    scanf("%d", &height);

    printf("width:  ");
    scanf("%d", &width);

    // interpret user input and present solution
    area = width*height;
    printf("area:   %d sq in", area);
}

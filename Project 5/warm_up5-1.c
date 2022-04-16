// Ethan Vosburg
// April 15, 2022

// In this short assignment you will a program that prompts
// the user to input the prices of three items. It then displays
// the prices with the least expensive displayed first.

#include <stdio.h>


// Get price input from player with validation
int getPrice(char prompt[], int min, int max){
    int usrInt;
    
    printf("%s", prompt);
    scanf("%d", &usrInt );

    // Validate user interger entry
    while (usrInt<min)
    {
        printf("Please enter an interger between %d and %d: ", min, max);
        scanf("%d", &usrInt );
    }

    // Return validated responce
    return usrInt;
};

void usr_input(float *price){

    if(price > 0){
        
    }

}

int main(){

}
// Ethan Vosburg
// April 15, 2022

// In this short assignment you will a program that prompts
// the user to input the prices of three items. It then displays
// the prices with the least expensive displayed first.

#include <stdio.h>


// Get price input from player with validation
float getPrice(char prompt[], int min){
    float usrInt;
    
    printf("%s", prompt);
    scanf("%f", &usrInt );

    // Validate user interger entry
    while (usrInt<min)
    {
        printf("Please enter an interger greater than %d: ", min);
        scanf("%f", &usrInt );
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
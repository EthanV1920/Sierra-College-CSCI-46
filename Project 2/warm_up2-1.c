// Ethan Vosburg
// February 24th, 2022

// Create a program to generate a Collatz sequence. Prompt the user to enter a
// positive integer. If the user enters an invalid integer, re-prompt the user
// until the number is positive. Print out the Collatz sequence. Print out the
// length of the sequence.

// import libraries
#include <stdio.h>
#include <math.h>

// collect user input for option 1
int usrIn(){

    int start_num = -1;

    while (start_num<0)
    {
        printf("Please enter a positive interger: ");
        scanf("%d", &start_num );
    }
        return start_num;
}

// generate the next interger in Collatz sequence
int collatz(long x){

    if(x % 2==0){
        return x / 2;
    }else{
        return (x*3)+1;
    }   

}

// determine which option the user wants and run
int main(){
    
    int usr_option = 0;

    printf("\n Which task would you like to do:\n    1. Find the Collatz Sequenece for a number\n    2. Find a number between 1 and 100 that give the largest sequence");

    // Validate user input
    while (usr_option <1 || usr_option >2)
    {
        printf("\n\nPlease select an option: ");
        scanf("%d", &usr_option );
    } 

    // option 1 user entered number
    if (usr_option == 1){
        
        int len = 1;
        printf("\n");

        for(int i = usrIn(); i != 1; i = collatz(i)){

            printf("%d, ", i);  
            len ++;

        }
        printf("1\n\nLength: %d\n", len);
    }
    
    // option 2 determine largest sequence between 1 and 1000
    if(usr_option == 2){
        int longest_sequence = 1;
        int longest_sequence_length = 1;
        int len;

        for (int j = 1; j <= 1000; j ++){

            len = 1;
            
            for(int i = j; i != 1; i = collatz(i)){
                // printf("%d, ", i); 
                len ++;
            }
            if (len > longest_sequence){
                longest_sequence_length = len;
                longest_sequence = j;
            }
        }
        printf(" The longest sequence is %d with a length of %d\n", longest_sequence, longest_sequence_length);
    }
}
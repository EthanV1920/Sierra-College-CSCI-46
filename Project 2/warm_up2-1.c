// Ethan Vosburg
// February 24th, 2022

// Create a program to generate a Collatz sequence. Prompt the user to enter a
// positive integer. If the user enters an invalid integer, re-prompt the user
// until the number is positive. Print out the Collatz sequence. Print out the
// length of the sequence.

#include <stdio.h>
#include <math.h>

int usrIn(){

    int start_num = -1;

    while (start_num<0)
    {
        printf("Please enter a positive interger: ");
        scanf("%d", &start_num );
    }
        return start_num;
}

int collatz(long x){

    if(x % 2==0){
        return x / 2;
    }else{
        return (x*3)+1;
    }   

}

int main(){
    
    int len;

    for(int i = usrIn(); i != 1; i = collatz(i)){

        printf("%d, ", i);  
        len +=1;

    }

    printf("1\nLength: %d", len);

}
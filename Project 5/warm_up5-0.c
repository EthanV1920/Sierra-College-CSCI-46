// Ethan Vosburg
// April 15, 2022

// In this assignment, we will be filling an array using pointers.

// Elements 0-9 	The values 0..9
// Elements 10-19 	The values 100, 110, 120, ..., 190
// Elements 20-25 	The values 4, 8, 15, 16, 23, 42 {2^n -2^n-1}
// Elements 26-39 	The first fourteen values in the Collatz sequence, starting with 7


#include <stdio.h>

#define ARRAY_LENGTH 40 
#define COLLATZ_START 7

int collatz(long x){

    if(x % 2==0){
        return x / 2;
    }else{
        return (x*3)+1;
    }   

}

void section_a( int *ptr_array){

    for( int i = 0; i <= 9; i++){
        ptr_array[i] = i;
    }

}

void section_b( int *ptr_array){

    for( int i = 10; i <= 19; i++){
        ptr_array[i] = i*10;
    }

}

void section_c( int *ptr_array){
    int randomValues[6] = {4, 8, 15, 16, 23, 42};


    for( int i = 20; i <= 25; i++){
        ptr_array[i] = randomValues[i-20];
    }

}

void section_d( int *ptr_array){
    ptr_array[26] = COLLATZ_START;

    for( int i = 27; i <= 39; i++){
        ptr_array[i] = collatz(ptr_array[i-1]);
    }

}


void printArray(int interger_array[]){
  for (int j = 0; j < 39; j++ ) {
      printf("Element[%d] = %d\n", j, interger_array[j] );
   }
}

int main(){
    int interger_array[ARRAY_LENGTH];

    int *ptr;

    ptr = interger_array;

    interger_array[0] = 45;

    section_a(ptr);
    section_b(ptr);
    section_c(ptr);
    section_d(ptr);

    printArray(interger_array);
   

}
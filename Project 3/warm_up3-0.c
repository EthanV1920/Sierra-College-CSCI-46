// Ethan Vosburg
// March 19th, 2022

// In this short assignment you will declare fill an integer array with values as described here

// Elements 0-9 	The values 0..9
// Elements 10-19 	The values 100, 110, 120, ..., 190
// Elements 20-25 	The values 4, 8, 15, 16, 23, 42 {2^n -2^n-1}
// Elements 26-39 	The first fourteen values in the Collatz sequence, starting with 7


#include <stdio.h>

#define ARRAY_LENGTH 40 

int collatz(long x){

    if(x % 2==0){
        return x / 2;
    }else{
        return (x*3)+1;
    }   

}

int printArray(int interger_array[]){
  for (int j = 0; j < 39; j++ ) {
      printf("Element[%d] = %d\n", j, interger_array[j] );
   }
}

int main(){
    int interger_array[ARRAY_LENGTH];

    interger_array[0] = 45;

    printArray(interger_array);
    // printf("%d", interger_array[0]);

}
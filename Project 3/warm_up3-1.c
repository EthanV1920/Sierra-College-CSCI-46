// Ethan Vosburg
// March 23, 2022

// This is a short program in which you will copy values out of one array and
// into another based on whether the values are positive, negative, or zero.
// A template program has been provided for you; to complete this assignment
// you will fill out the center portion.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Change this constant to 1 to fill source array
// with random values.
#define RAND_ARR 1

#define SRC_SIZE 10

// Print array function
void printArray(int interger_array[], int length){
  for (int j = 0; j < length; j++ ) {
      printf("Element[%d] = %d\n", j, interger_array[j] );
   }
}

int main()
{
    // Declare source array
    int source[SRC_SIZE];
    
    // Declare vaiables
    int pos_array_size = 0;
    int neg_array_size = 0;

    
    // Fill array with random values or constant values
    if (RAND_ARR == 1)
    {
        // Seed random number generator
        srandom(time(NULL));
        
        // Fill array with random values
        for (int i = 0; i < SRC_SIZE; i++)
            source[i] = random() % 20 - 10;
    }
    else
    {
        // Fill array with constant values
        source[0] = 9;
        source[1] = 2;
        source[2] = 0;
        source[3] = -4;
        source[4] = 0;
        source[5] = 21;
        source[6] = -92;
        source[7] = 1;
        source[8] = 10;
        source[9] = 2;
    }
    
    for(int i = 0; i <= 9; i ++){
        if (source[i] > 0){
            pos_array_size ++;
        }else if (source[i] < 0){
            neg_array_size ++;
        }
    }
    
    // Declare pos and neg arrays
    int neg[neg_array_size];
    int pos[pos_array_size];

    // Declare pos and neg arrray indecies
    int x = 0;
    int y = 0;

    // Copy positice src values to pos and negatice src values to neg
    for(int i = 0; i <= SRC_SIZE; i ++){
        if (source[i] > 0){
            pos[x] = source[i];
            x ++;
        }else if (source[i] < 0){
            neg[y] = source[i];
            y ++;
        }
    }
    
    // printArray(source, SRC_SIZE);

    // Display the contents of the pos array
    printf("\npos: \n");
    printArray(pos, pos_array_size);

    printf("\nneg: \n");
    printArray(neg, neg_array_size);    

}
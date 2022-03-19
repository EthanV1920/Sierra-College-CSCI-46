// Ethan Vosburg
// February 24th, 2022 

// Write a C function to calculate the sigmoid function and present it as a table. 
// The main function should generate a table and a second function should calculate
// the sigmoid function.

// include libraries
#include <stdio.h>
#include<math.h>

// declare the table constructor function to make rows of a table
void table_constructor(int rowtype,float x,float y){
    // look for row_type flag to determine if desired row is a header row or not
    if(rowtype==0){
        printf("\n     Sigmoid Function Table\n________________________________");
    }else{
        // ajdust spacing based on positive and negative values
        if(x<0){
            printf("\n      %.2f    |    %.3f", x,y);
        }else{
            printf("\n       %.2f    |    %.3f", x,y);
        }
    }
}

// declare sigmoid function
float sigmoid(float x){
    return (1/(1+exp(-x)));
}

// declare main function
int main(){

    int range_min = -5;
    int range_max = 5;

    table_constructor(0,0,0);

    // construct table
    for(int i = range_min; i<range_max; i+=1){
        table_constructor(1,i,sigmoid(i));
    }

    printf("\n");

}


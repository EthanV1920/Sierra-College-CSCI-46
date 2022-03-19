// Ethan Vosburg
// March 19th, 2022

// In this short assignment you will declare fill an integer array with values as described here

// Elements 0-9 	The values 0..9
// Elements 10-19 	The values 100, 110, 120, ..., 190
// Elements 20-25 	The values 4, 8, 15, 16, 23, 42 {2^n -2^n-1}
// Elements 26-39 	The first fourteen values in the Collatz sequence, starting with 7


int collatz(long x){

    if(x % 2==0){
        return x / 2;
    }else{
        return (x*3)+1;
    }   

}
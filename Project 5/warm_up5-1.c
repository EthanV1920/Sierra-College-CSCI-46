// Ethan Vosburg
// April 15, 2022

// In this short assignment you will a program that prompts
// the user to input the prices of three items. It then displays
// the prices with the least expensive displayed first.

#include <stdio.h>

#define PRICE_COUNT 3

// Get price input from user with validation
float getPrice(char prompt[], int index){
    float usrInt;
    
    printf("%s %d: ", prompt, index);
    scanf("%f", &usrInt );

    // Validate user interger entry
    while (usrInt<0)
    {
        printf("Please enter an interger greater than %d: ", 0);
        scanf("%f", &usrInt );
    }

    // Return validated responce
    return usrInt;
};

// Gather inputs from user
void usr_input(float *price){
    for(int i=0; i<PRICE_COUNT; i++){
        price[i] = getPrice("Please enter a price", i+1);
    }

}

int isSorted(float *price, int length){
    int is_sorted = 1;
    // Checking if any values are out of order
    for(int i = 0; i < length-1;i++){
        if(price[i] > price[i+1]){
            is_sorted = 0;
        }
    }
    // Returning sorted state of board 0 = !sorted 1 = sorted
    return is_sorted;
}


void sort(float *price){
    float temp0, temp1;
    while(!isSorted(price,PRICE_COUNT)){
        for(int i=0; i<PRICE_COUNT-1; i++){
        if(price[i] > price[i+1]){
            temp0 = price[i];
            temp1 = price[i+1];
            
            price[i] = temp1;
            price[i+1] = temp0;
        }
    }
    }
}

void printArray(float *array){
  for (int j = 0; j < PRICE_COUNT; j++ ) {
      printf("%0.2f ", array[j] );
   }
}


int main(){
    float prices[PRICE_COUNT];
    float *price[PRICE_COUNT];
    *price = prices;

    usr_input(*price);
    sort(*price);
    printf("Prices:");
    printArray(*price);
   

}
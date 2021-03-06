// Ethan Vosburg
// February 21st, 2022

// The grill is a rectangle. The user will supply the width
// and height of the grill, in that order. Your program will
// draw a picture of a rectangular grill. Here is one that
// is 12 wide and 4 tall.

// +----------+
// |----------|
// |----------|
// +----------+

#include <stdio.h>

int main(){

    int
    height,
    height_min,
    height_max,
    width,
    width_min,
    width_max,
    check_flag,
    i,
    j;

    height_min = 2;
    height_max = 12;
    width_min = 2;
    width_max = 30;
    check_flag = 0;

    // accept user input
    printf("height: ");
    scanf("%d", &height);

    printf("width:  ");
    scanf("%d", &width);

    // validates user input and adds a check flag
    if(height < height_min){
        printf("height too low\nPlease enter a height value that is between %d and %d\n", height_min, height_max);
    }else if(height > height_max){
        printf("height too high\nPlease enter a height value that is between %d and %d\n", height_min, height_max);
    }else{
        check_flag +=1;
    }

    if(width < width_min){
        printf("Width too low\nPlease enter a width value that is between %d and %d\n",width_min, width_max);
    }else if(width >= width_max){
        printf("Width too high\nPlease enter a width value that is between %d and %d\n",width_min, width_max);
    }else{
        check_flag +=1;
    }

    // iterates with validated user data to asseble ascii image
    if(check_flag == 2){
        for (j=0; j < height; j += 1){
            if(j == 0 || j == height-1){
                for(i=0; i < width; i += 1){
                    if(i == 0 || i == width-1){
                    printf("+");
                    }else{
                        printf("-");
                    }
                }
            }else{               
                for(i=0; i < width; i += 1){
                    if(i == 0 || i == width-1){
                        printf("|");
                    }else{
                        printf("-");
                    }
                }
            }
        printf("\n");
        } 
    }

}
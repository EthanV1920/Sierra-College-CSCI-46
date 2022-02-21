// Ethan Vosburg
// February 10th 2021

// Write a program named sumfrac.c that prompts the user to enter two fractions,
// each of the form n/d. The program then adds the fractions together and displays
// the resulting fraction. You don't have to reduce the answer.


#include <stdio.h>

int main(){

    int num_one, 
        den_one, 
        num_two, 
        den_two,
        num_solution,
        den_solution,
        num_proper,
        den_proper,
        whole_proper;

    printf("Enter fraction 1 :");
    scanf("%d/%d", &num_one, &den_one);
    // printf("%d/%d", numerator_one, denominator_one);


    printf("Enter fraction 2 :");
    scanf("%d/%d", &num_two, &den_two);

    num_solution = num_one*den_two+num_two*den_one;
    den_solution = den_one*den_two;

    num_proper = num_solution%den_solution;
    den_proper = den_solution;
    whole_proper = (num_solution-num_proper)/den_proper; 


    printf("Solution: %d/%d\n", num_solution, den_solution);

    printf("Proper Solution: %d %d/%d\n", whole_proper, num_proper, den_proper);


}
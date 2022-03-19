// Ethan Vosburg
// March 9th, 2022

// Write a program that prompts the user for a dollar amount (a positive integer),
// then displays the minimum number of bills needed to add up to the given amount.
// Only a single number needs to be displayed.

// import libraries
#include <stdio.h>
#include <math.h>

// collect denominations
int usrDenominations(){
    int den1,
        den2,
        den3,
        den4,
        den5;

    int denominations[] = {den1, den2, den3, den4, den5};
    printf("1, 5, 10, 20, 100\nPlease enter your denomonations in the format above or press enter to use those defaults:");
    scanf("%d, %d, %d, %d, %d", &den1, &den2, &den3, &den4, &den5);
    return 1;

}

// collect user input
int usrIn(){

    int change_amount = -1;

    while (change_amount<0)
    {
        printf("\nPlease enter a positive interger: ");
        scanf("%d", &change_amount );
        if (change_amount < 0){printf("%d is not positive, please enter a new number", change_amount);}
    }
        return change_amount;
}


int main()
{
    printf("%d", usrDenominations());
    usrIn();

}

// Ethan Vosburg
// April 8th, 2022

// In this assignment you will implement a simple puzzle game called Reverse.
// This game uses an array of integers to store the state of the game.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Formatted instructions for player
void instructions(){
    printf("\n %30s \n\n", "Welcome to Reverse!");
    printf( "In this game you will create a board of length n\n"
            "and then reverse a select amount of numbers going\n"
            "from left to right until the numbers are in order.\n\n");
}

// Get interger input from player with validation
int getInt(char prompt[], int min, int max){
    int usrInt;
    
    printf("%s", prompt);
    scanf("%d", &usrInt );

    // Validate user interger entry
    while (usrInt>max || usrInt<min)
    {
        printf("Please enter an interger between %d and %d: ", min, max);
        scanf("%d", &usrInt );
    }

    // Return validated responce
    return usrInt;
};

// Fill empty board with numbers starting from 1 and going to board length
void fillBoard(int board[], int boardLength ){
    for (int i = 0; i < boardLength; i++){
        board[i] = i+1;
    }
}

// Print board with easy to understand formating
void printBoard(int interger_array[], int boardLength){
  printf("\n[");
    for (int j = 0; j < boardLength; j++ ) {
        if (j == boardLength-1){
            printf(" %d ", interger_array[j] );
        }else{
            printf(" %d |", interger_array[j] );
        }
    }
   printf("]");
}

// Shuffle board to initial game state
void shuffleBoard(int board[], int boardLength){
    int r, 
        i, 
        temp1,
        temp2;
    
    // Using Fisher–Yates shuffle algorithm 
    for(i = boardLength-1; i > 0; i--){
        // Using random function to pull a number from the board
        r = random() % boardLength;
        // Swaping two board places
        temp1 = board[i];
        temp2 = board[r];
        board[i] = temp2;
        board[r] = temp1;
    }
}

// Determine sorted state of board
int isSorted(int board[], int boardLength){
    int is_board = 1;
    // Checking if any values are out of order
    for(int i = 0; i < boardLength-1;i++){
        if(board[i] > board[i+1]){
            is_board = 0;
        }
    }
    // Returning sorted state of board 0 = !sorted 1 = sorted
    return is_board;
}

// Reverse range of numbers based on user input
void swapBoard(int board[], int swapRange){
    // Create a temp Board to store values to be reversed
    int tempBoard[swapRange];

    // Copy swap range to temp board
    for(int i = 0; i < swapRange; i++){
        tempBoard[i] = board[i];
    }

    // Reverse board values in swap range
    for(int i = 0; i < swapRange; i++){
        board[i] = tempBoard[swapRange-1-i];
    } 

}

int main(){

    // Initialize random seed and present instructions to player
    srandom(time(NULL));
    instructions();

    // Declare vaiable
    int boardLength = getInt("Enter board size: ", 3, 20),
        board[boardLength],
        turnCount = 0;

    // Set up board and present to player
    fillBoard(board, boardLength);
    shuffleBoard(board, boardLength);
    printBoard(board, boardLength);

    // Accepte user input and iterate through game
    while (!isSorted(board, boardLength)){
        swapBoard(board, getInt("   What range would you like to swap? ", 1, boardLength));
        printBoard(board, boardLength);
        turnCount ++;
    }

    // End game and present turn count
    printf("\n\nCongratulations! You won in %d moves.\n", turnCount);
    
}

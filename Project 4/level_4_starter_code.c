#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int getInt(char prompt[], int min, int max);


int main()
{
    // Seed the random number generator
    srandom(time(NULL));
        
    // Ask user for length of game, from 3-20
    int boardLength = getInt("Enter size of board: ", 3, 20);
    
    // Create board. Shuffle numbers.
    int board[boardLength];
    
    // Fill board in order with numbers 1..boardLength.
    fillBoard(board, boardLength);
    
    // Shuffle board.
    // I recommend initially only uncommenting the shuffleBoard line
    // so it doesn't get stuck in an infinite loop. Once shuffleBoard
    // is working, uncomment the rest of the loop.
    //while (isSorted(FILL THIS IN))
    //{
    //    shuffleBoard(FILL THIS IN);
    //}
    
    // Print board
    //printBoard(FILL THIS IN);
    
    int gameOver = 0;
    int moves = 0;
    while (!gameOver)
    {
        // Ask user for amount to reverse
        int amt = getInt("How many to reverse? ", 2, boardLength);
        
        // Reverse the first (amt) numbers
        //reverse(FILL THIS IN);
        
        // Print the board
        //printBoard(FILL THIS IN);
        
        // Check to see if the game is over
        //gameOver = isSorted(FILL THIS IN);
        
        moves++;
    }
    printf("You won in %d moves!\n", moves);
}

// Get an integer from the user.
//   Display the prompt.
//   Get input from user.
//   Check that the input is between the min and max, inclusive.
//   If not, display error message that includes the min and max,
//     then loop back to get input again.
int getInt(char prompt[], int min, int max)
{
    return -999;    // Remove this line and replace it with working code.
}
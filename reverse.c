#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int getInt(char prompt[], int min, int max);
void fillBoard(int board[], int boardLength);
void printBoard(int board[], int boardLength);
void shuffleBoard(int board[], int boardLength);
void reverse(int board[], int boardLength, int amt2);
int isSorted(int board[], int boardLength);


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
    while (isSorted(board, boardLength))
    {
        shuffleBoard(board, boardLength);
    }
    
    // Print board
    printBoard(board, boardLength);
    
    int gameOver = 0;
    int moves = 0;
    while (!gameOver)
    {
        // Ask user for amount to reverse
        int amt = getInt("How many to reverse? ", 2, boardLength);
        
        // Reverse the first (amt) numbers
        reverse(board, boardLength, amt);
        
        // Print the board
        printBoard(board, boardLength);
        
        // Check to see if the game is over
        gameOver = isSorted(board, boardLength);
        
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
    int result;

    for (;;) {
        printf("%s", prompt);
        scanf("%d", &result);

    if (result < min || result > max) {
        printf("Please enter a integer between %d - %d\n", min, max);
    } 
    else {
        break;
    }
       // Remove this line and replace it with working code.
    }
    return result;
}

void fillBoard(int board[], int boardLength) {
	for(int i = 0; i < boardLength; i++) {
		board[i] = i + 1;
	}
}

void printBoard(int board[], int boardLength) {
	printf("Board: ");
	    for (int i = 0; i < boardLength; i++ ) {
		    printf("%d ", board[i]);
	    }
	printf("\n");
}


void shuffleBoard(int board[], int boardLength) {
	for (int i = boardLength - 1; i >= 1; i--) {
 		int j = random() % (i + 1);

		int shuff = board[i];
		board[i] = board[j];
		board[j] = shuff;
	}
}

void reverse(int board[], int boardLength, int amt2) {

	for (int i = 0; i < amt2 / 2; i++) {
		int rev = board[amt2 - 1 - i];
        board[amt2 - 1 - i] = board[i];
        board[i] = rev;
	}
}

int isSorted(int board[], int boardLength) {
	for (int i = 0; i < boardLength -1; i++) {
		if (board[i] > board[i+1]) {
			return 0;
		}
	}
	return 1;
}


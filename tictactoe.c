#include <stdio.h>
#include <stdbool.h>

// Function to print the Tic-Tac-Toe board
void printBoard(char board[3][3]) {
    printf("\n");
    int i,j;
	for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

// Function to check if the game is over
bool isGameOver(char board[3][3], char player) {
    // Check rows, columns, and diagonals
    int i,j;
    for (i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Columns
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Diagonal (top-left to bottom-right)
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Diagonal (top-right to bottom-left)

    // Check for a tie (all cells filled)
    for (i = 0; i < 3; ++i) {
        for ( j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false; // Found an empty cell
        }
    }

    return true; // It's a tie
}

int main() {
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } }; // Initialize an empty 3x3 board
    char currentPlayer = 'X';
    int row, col;
    bool validMove = false;

    printf("Welcome to Tic-Tac-Toe!\n");

    while (true) {
        printBoard(board);

        validMove = false;
        while (!validMove) {
            printf("Player %c, enter your move (row and column): ", currentPlayer);
            if (scanf("%d %d", &row, &col) != 2 || row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                printf("Invalid move. Try again.\n");
                while (getchar() != '\n'); // Clear input buffer
            } else {
                validMove = true;
            }
        }

        board[row][col] = currentPlayer;

        if (isGameOver(board, currentPlayer)) {
            printBoard(board);
            if (currentPlayer == 'X') {
                printf("Player X wins!\n");
            } else {
                printf("Player O wins!\n");
            }
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}


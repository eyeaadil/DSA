#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

// Function to check if there is a winner
char checkWinner(const vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != '.' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] != '.' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }
    // Check diagonals
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return '.';
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == '.') {
                return false;
            }
        }
    }
    return true;
}

// Function to play Tic-Tac-Toe
void playTicTacToe() {
    vector<vector<char>> board(3, vector<char>(3, '.')); // Initialize the board with empty cells
    char currentPlayer = 'X'; // Player X starts the game

    while (true) {
        cout << "Current board:" << endl;
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        int row, col;
        cin >> row >> col;

        // Check if the cell is valid and not already filled
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != '.') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row][col] = currentPlayer;

        // Check for winner or draw
        char winner = checkWinner(board);
        if (winner != '.') {
            cout << "Player " << winner << " wins!" << endl;
            break;
        } else if (isBoardFull(board)) {
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    cout << "Let's play Tic-Tac-Toe!" << endl;
    playTicTacToe();
    return 0;
}

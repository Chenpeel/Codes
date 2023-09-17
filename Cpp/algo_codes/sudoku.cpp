#include <iostream>
#include <random>
#include <vector>
using namespace std;

bool isValid(vector<vector<char> >& board, int row, int col, char num) {
  // Check row and column
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == num || board[i][col] == num) {
      return false;
    }
  }
  // Check 3x3 grid
  int startRow = 3 * (row / 3);
  int startCol = 3 * (col / 3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[startRow + i][startCol + j] == num) {
        return false;
      }
    }
  }
  return true;
}

bool solveSudoku(vector<vector<char> >& board) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (board[row][col] == '.') {
        for (char num = '1'; num <= '9'; num++) {
          if (isValid(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board)) {
              return true;
            }
            board[row][col] = '.';  // Backtrack
          }
        }
        return false;  // All numbers are tried, backtrack
      }
    }
  }
  return true;  // All empty cells are filled
}

void printBoard(const vector<vector<char> >& board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

void generateSudoku(vector<vector<char> >& board, int numClues) {
  // Initialize the board with '.'
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      board[i][j] = '.';
    }
  }

  // Fill in random numbers with valid rules
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(1, 9);

  for (int i = 0; i < numClues; i++) {
    int row, col, num;
    do {
      row = dis(gen) - 1;
      col = dis(gen) - 1;
    } while (board[row][col] != '.');

    num = dis(gen) + '0';
    if (isValid(board, row, col, num)) {
      board[row][col] = num;
    }
  }
}

int main() {
  vector<vector<char> > board(9, vector<char>(9));
  generateSudoku(board, 30);  // Generate a Sudoku puzzle with 30 clues
  cout << "Generated Sudoku board:" << endl;
  printBoard(board);
  cout << endl << "Solved Sudoku board:" << endl;
  solveSudoku(board);
  printBoard(board);

  return 0;
}
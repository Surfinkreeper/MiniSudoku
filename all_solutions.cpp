#include <iostream>
#include <utility>
#include<vector>
using namespace std;

const int BOARD_SIZE = 3;
const int EMPTY_CELL = 0;

void printBoard(int board[][BOARD_SIZE]);
bool solveSudoku(int board[][BOARD_SIZE], int cell, int &solutioncount);
bool isValid(int board[][BOARD_SIZE], int row, int col, int num);

void printBoard(int board[][BOARD_SIZE]) {
    for(int r = 0; r < BOARD_SIZE; r++) {
        for(int c = 0; c < BOARD_SIZE; c++) {
            if(board[r][c] == EMPTY_CELL) {
                cout << "   ";
            }
            else {
                cout << " " << board[r][c] << " ";
            }
        }
        cout << endl;
    }
}

bool solveSudoku(int board[][BOARD_SIZE], int cell, int &solutioncount) {

    int row = cell/3;
    int col = cell%3;

    if( cell == 9 ) {
        //prints solution then backtracks to find another
        solutioncount++;
        printBoard(board);
        cout << "Solution " << solutioncount << endl << endl;
        return false;
    }

    if(board[row][col] != EMPTY_CELL) {
        return solveSudoku(board, cell + 1, solutioncount);
    }

    for(int i = 1; i <= 3; i++) {
        if(isValid(board, row, col, i)) {
            board[row][col] = i;
            if(solveSudoku(board, cell + 1, solutioncount)) {
                return true;
            }
            //sets back to zero if the above returns false
            board[row][col] = EMPTY_CELL;
        }
    }

    return false;
}

bool isValid(int board[][BOARD_SIZE], int row, int col, int num) {

    //check row or colum
    for(int i = 0; i < BOARD_SIZE; i++ ) {
        //check row
        if(board[i][col] == num) {
            return false;
        }
        //check column
        if(board[row][i] == num) {
            return false;
        }
    }

    return true;
}

int main() {

    int board1[BOARD_SIZE][BOARD_SIZE] = {
       {EMPTY_CELL, 2, EMPTY_CELL}, 
       {3, 1, EMPTY_CELL}, 
       {EMPTY_CELL, 3, EMPTY_CELL} 
    };

    int board2[BOARD_SIZE][BOARD_SIZE] = {
       {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
       {1, EMPTY_CELL, EMPTY_CELL}, 
       {EMPTY_CELL, 3, EMPTY_CELL} 
    };

    int board3[BOARD_SIZE][BOARD_SIZE] = {
       {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL},
       {1, EMPTY_CELL, EMPTY_CELL}, 
       {EMPTY_CELL, EMPTY_CELL, EMPTY_CELL} 
    }; 

    int solutioncount = 0;

    solveSudoku(board1, 0, solutioncount);
    solutioncount = 0;
    solveSudoku(board2, 0, solutioncount);
    solutioncount = 0;
    solveSudoku(board3, 0, solutioncount);

    return 0;
}
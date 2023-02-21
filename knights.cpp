#include <iostream>
#include <string>
using namespace std;


/*
current issues:
- array reference parameters (passing 2d arrays and array-pointer duality??..)
- char array?? problems with char and string conversions
- no tests have been done...
*/

const int ROW = 5;
const int COL = 5;
string knight = "N";
int valid_moves = 0;

void print_board(std::string *board, int row, int col){ //array pointer duality valid here??
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            board[i][j] = "0";
        }
    }
}

void solve(std::string *board, int row, int col, bool &solved, int goal){
    //if all have been visited: we are done (all visted when 5x5 = 25 valid moves are made?)
    //else if we're in a wall (outside the board) or a path we've hit: go back
    //else try to solve recursively by going in each of the possible L shapes (2,1)(1,2) sequence
    if (valid_moves == goal){
        solved = true;
        return;
    }
    if (row >= ROW || col >= COL || board[row][col] == knight || board[row][col] != "0"){
        return;
    }

    board[row][col] = knight;
    print_board(board, ROW, COL);

    if (!solved) solve(board, row+1, col + 2, solved, goal); //(1,2)
    if (!solved) solve(board, row+2, col + 1, solved, goal); //(2,1)
    if (!solved) solve(board, row-1, col - 2, solved, goal);
    if (!solved) solve(board, row-2, col - 1, solved, goal);
    if (!solved){ //visted
        board[row][col] = char(valid_moves + 1); //doesnt work when i do to_string... but array is intialized as strings???
        valid_moves = valid_moves + 1;
    }
}

int main(){
    std::string board[ROW][COL];
    //set all to 0 (unvisited)
    for (int i = 0; i < ROW; i++){
        for (int j = 0; j < COL; j++){
            board[i][j] = "0";
        }
    }
    int goal = ROW * COL;
    bool solved = false;
    print_board(*board, ROW, COL);
    solve(*board, 0, 0, solved, goal); //start at (0,0)

}
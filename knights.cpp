#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// 5x5 board
const int ROW = 5;
const int COL = 5;

// print board function
void print_board(std::string board[][COL], int row, int col) {
  for (int i = 0; i < row; i++) {
    std::cout << "\n";
    for (int j = 0; j < col; j++) {
      std::cout << std::setw(3) << board[i][j];
    }
  }
  std::cout << std::endl;
}

// moved valid_moves variable into function parameters
// to better keep control the value as moves are being recursively called
void solve(std::string board[][COL], int row, int col, bool &solved, int goal,
           int valid_moves) {
  if (valid_moves > goal) {
    solved = true;
    return;
  }
  if (row > ROW - 1 || row < 0 || col > COL - 1 || col < 0 ||
      board[row][col] != "0") {
    return;
  }

  board[row][col] = std::to_string(valid_moves);

  /*valid_moves start from 1 (first position)
  and increment by 1 inside of function call instead of outside
  for every following valid move made*/

  if (!solved) {
    solve(board, row + 1, col + 2, solved, goal, valid_moves + 1); //(1,2)
    solve(board, row + 1, col - 2, solved, goal, valid_moves + 1); //(1,2)
    solve(board, row + 2, col + 1, solved, goal, valid_moves + 1); //(2,1)
    solve(board, row + 2, col - 1, solved, goal, valid_moves + 1);
    solve(board, row - 1, col + 2, solved, goal, valid_moves + 1);
    solve(board, row - 1, col - 2, solved, goal, valid_moves + 1);
    solve(board, row - 2, col + 1, solved, goal, valid_moves + 1);
    solve(board, row - 2, col - 1, solved, goal, valid_moves + 1);
  }

  // implement if visted feature where if the move wasnt solved then to reset to
  // 0
  if (!solved) {
    board[row][col] = "0";
    return;
  }
}

int main() {
  std::string board[ROW][COL]; // create board

  // set all to 0 (unvisited)
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      board[i][j] = "0";
    }
  }
  int goal = ROW * COL; // 5x5 board should have a goal of 25 possible positions
  bool solved = false;

  std::cout << "Starting Knights Board: \n";
  print_board(board, ROW, COL);

  std::cout << "-------------------\nSolved Knights Board: \n";
  std::cout << "Start position = (0,0)\n";
  solve(board, 0, 0, solved, goal, 1); // start position 1 [valid_move parameter] at (0,0)
  print_board(board, ROW, COL);

  return 0;
}
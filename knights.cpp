#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

const int ROW = 5;
const int COL = 5;
std::string knight = "N";
int valid_moves = 0;

void print_board(std::string board[][COL], int row, int col) {
  for (int i = 0; i < row; i++) {
    std::cout << "\n";
    for (int j = 0; j < col; j++) {
      std::cout << setw(3) << board[i][j];
    }
  }
}

void solve(std::string board[][COL], int row, int col, bool &solved, int goal,
           int move) {
  if (valid_moves > goal) {
    solved = true;
    return;
  }
  if (row > ROW - 1 || row < 0 || col > COL - 1 || col < 0 ||
      (board[row][col] == knight && valid_moves < 26) ||
      board[row][col] != "0") {
    return;
  }

  board[row][col] = to_string(valid_moves++);

  if (!solved) {
    solve(board, row + 1, col + 2, solved, goal, 1); //(1,2)
    solve(board, row + 1, col - 2, solved, goal, 2); //(1,2)
    solve(board, row + 2, col + 1, solved, goal, 3); //(2,1)
    solve(board, row + 2, col - 1, solved, goal, 4);
    solve(board, row - 1, col + 2, solved, goal, 5);
    solve(board, row - 1, col - 2, solved, goal, 6);
    solve(board, row - 2, col + 1, solved, goal, 7);
    solve(board, row - 2, col - 1, solved, goal, 8);
  }

  // implement if visted feature where if the move wasnt solved then to remove
  // the previous number (backtrack) -- if no progress today post on zulip for
  // class and zamansky to review
}

int main() {
  std::string board[ROW][COL]; // create board
  // set all to 0 (unvisited)
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      board[i][j] = "0";
    }
  }
  int goal = ROW * COL;
  bool solved = false;
  std::cout << "Starting Knights Board: \n";
  print_board(board, ROW, COL);
  std::cout << "\n-------------------\nSolved Knights Board";
  solve(board, 0, 0, solved, goal, 0); // start at (0,0)
  print_board(board, ROW, COL);
  return 0;
}
#include "Board.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  Board sudoku(string(argv[1]) + ".out.fastSudoku");
  if (argc >= 2) {
    fstream s(argv[1], s.in);
    sudoku.read(s);
  } else {
    sudoku.read(cin);
  }
  sudoku.write();
  bool c=false;
  if (argc >= 3) {
    c = string(argv[2]) == "count";
  }
  if (c) {
    sudoku.countM = true;
  };
  sudoku.algorithm();
  if (c) {
    sudoku.out << "Sudoku solutions : " << sudoku.count << endl;
  } else {
    sudoku.write();
  };
  return 0;
}
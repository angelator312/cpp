#include "Index.hpp"
#include <iostream>
using namespace std;
struct IB {
  Index ind;
  bool b;
  IB(Index ind, bool b) {
    this->ind = ind;
    this->b = b;
  }
};
struct Board {
  int board[9][9]{};
  bool eInSquare(Index ind, int e) {
    Index i = ind.startOfSquare();
    do {
      if (i.x == ind.x && i.y == ind.y)
        continue;
      if (board[i.y][i.x] == e) {
        return false;
      }
    } while (i.nextInSquare());
    return true;
  };
  bool eInRow(Index ind, int e) {
    Index i = ind.startOfRow();
    do {
      if (i.x == ind.x)
        continue;
      if (board[i.y][i.x] == e) {
        return false;
      }
    } while (i.nextInRow());
    return true;
  };
  bool eInCol(Index ind, int e) {
    Index i = ind.startOfCol();
    do {
      if (i.y == ind.y)
        continue;
      if (board[i.y][i.x] == e) {
        return false;
      }
    } while (i.nextInCol());
    return true;
  };
  bool eInPlace(Index ind, int e) {
    return eInCol(ind, e) && eInRow(ind, e) && eInSquare(ind, e);
  };
  void read() {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char e;
        cin >> e;
        if (e == '.') {
          e = '0';
        }
        if (e < '0' || e > '9') {
          cerr << "Invalid entry : " << e << endl;
          exit('p');
        }
        board[i][j] = e - '0';
      }
    }
  };
  void write() {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char e = '0' + board[i][j];
        if (e == '0') {
          e = '.';
        }
         // cout << e << " ";
        if (j % 3 == 2 && j>0) {
           // cout << "| ";
        }
      }
      if (i % 3 == 2 && i>0) {
         // cout << endl << "------|-------|-------|";
      }
       // cout << endl;
    }
  };
  bool brutAlgorithm(Index ind) {
    int e = 1;
    if (board[ind.y][ind.x] > 0) {
      ind.next();
    }

    if (!ind.isValid()) {
       // cout << "Ind is not valid" << endl;
      return true;
    }

    Index ind2 = ind;
    ind2.next();
    while (true) {
      //  // cout << e << endl;
      if (e == 10) {
        board[ind.y][ind.x] = 0;
        return false;
      }
      board[ind.y][ind.x] = e;
      bool place = eInPlace(ind, e);
       // cout << "[" << ind.toString() << "] |" << place << "| e:" << e << endl;
      if (place) {
         // cout << e << " :e ind.x: " << ind.x << " ind.y: " << ind.y << endl;
        //  // cout << "Check and check index 2" << endl;
        if (brutAlgorithm(ind2)) {
          return true;
        } else {
          e++;
        }
      } else {
        e++;
      }
    }
    return false;
  };
};

int main() {
  Board sudoku;
  sudoku.read();
  Index ind(0, 0);
  sudoku.write();
   // cout << sudoku.brutAlgorithm(ind) << endl;
  sudoku.write();
}
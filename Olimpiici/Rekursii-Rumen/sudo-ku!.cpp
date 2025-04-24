#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int N = 10;
const int P = 10;
int board[N][N];
bool checkBox(int xB, int yB, int idea) {
  bool b[10] = {
      false, false, false, false, false, false, false, false, false, false,
  };
  for (int y = yB * 3 + 1; y < (yB + 1) * 3 + 1; ++y) {
    for (int x = xB * 3 + 1; x < (xB + 1) * 3 + 1; ++x) {
      b[board[x][y]] = true;
    }
  }
  if (b[idea])
    return false;
  return true;
}
bool pass(int x, int y, int idea) {
  // check row
  for (int j = 1; j < 10; ++j) {
    if (board[x][j] == idea)
      return false;
  }
  // check col
  for (int i = 1; i < 10; ++i) {
    if (board[i][y] == idea)
      return false;
  }
  // check box
  return checkBox((x - 1) / 3, (y - 1) / 3, idea);
}
bool solve(int x, int y) {
  if (x == 9 && y == 10)
    return true;
  if (y == 10) {
    x++;
    y = 1;
  }
  if (board[x][y] > 0) {
    return solve(x, y + 1);
  }
  for (int i = 1; i < 10; i++) {
    // cerr << y << " " << x << " " << i << " ";
    if (pass(x, y, i)) {
      ////cerr << "stava\n";
      board[x][y] = i;
      if (solve(x, y + 1))
        return true;
    }
    // cerr << "ne stava\n";
  }
  board[x][y] = 0;
  return false;
}

int main() {
  for (int i = 1; i < 10; i++) {
    for (int  x = 1; x < 10; x++)
    {
        cin>>board[x][i];
    }
    
  }
  //*
  // cerr <<
  solve(1, 1);
  // << endl;
  for (int i = 1; i < 10; i++) {
    for (int j = 1; j < 10; j++) {
      cout << board[j][i]<<" ";
    }
    cout << endl;
  }
  //*/
  return 0;
}
#include <iostream>
using namespace std;
struct Index {
  int y = 0, x = 0;
  Index(int x, int y) {
    this->y = y;
    this->x = x;
  };
  Index() {
  };
  bool isValid() {
    return (this->y >= 0 && this->y <= 8) && (this->x >= 0 && this->x <= 8);
  };
  bool next() {
    x++;
    if (x == 9) {
      x = 0;
      y++;
      if (y == 9) {
        return false;
      }
    }
    return true;
  };
  string toString() { return "y: " + to_string(y) + ", x: " + to_string(x); };
  Index startOfRow() { return Index(0, y); };
  Index startOfCol() { return Index(x, 0); };
  Index startOfSquare() {
    int sX = (x / 3) * 3, sY = (y / 3) * 3;
    return Index(sX, sY);
  };
  bool nextInRow() {
    x++;
    if (x == 9) {
      return false;
    }
    return true;
  };
  bool nextInCol() {
    y++;
    if (y == 9) {
      return false;
    }
    return true;
  };
  bool nextInSquare() {
    int sIX = x % 3, sIY = y % 3;
    sIX++;
    if (sIX == 3) {
      x = (x / 3) * 3;
      sIX = 0;
      sIY++;
      if (sIY == 3) {
        return false;
      }
      y++;
    } else {
      x++;
    }
    return true;
  };
};
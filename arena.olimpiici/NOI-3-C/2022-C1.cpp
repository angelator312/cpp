#include <stdio.h>
#define endl "\n"
// using namespace std;
int left, right, up, down;
inline void read() {
  char ch = getchar();
  while (true) {
    if (ch == 'L')
      --left;
    else if (ch == 'R')
      ++left;
    else if (ch == 'U')
      --up;
    else if (ch == 'D')
      ++up;
    else
      break;
    ch = getchar();
  }
}
int main() {
  read();
  if (left == 0 && up == 0) {
    printf("0");
    return 0;
  }
  if (left < 0) {
    right = -left;
    left = 0;
  }
  if (up < 0) {
    down = -up;
    up = 0;
  }
  //   std::cerr << left << " " << right << " " << up << " " << down << endl;
  while (up--)
    printf("U");
  while (down--)
    printf("D");
  while (left--)
    printf("L");
  while (right--)
    printf("R");
  printf(endl);
  //   std::couts << std::string(up, 'U');
  //   std::cout << std::string(down, 'D');
  //   std::cout << std::string(left, 'L');
  //   std::cout << std::string(right, 'R') << "\n";
  return 0;
}
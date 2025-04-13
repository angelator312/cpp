#include <iostream>
using namespace std;
void printSquare(int k) {
  for (int i = 1; i <= k; i++) {
    for (int j = 0; j < k; j++) {
      cout << (i + j) % 10 << " ";
    }
    cout << endl;
  }
}
void printTriangle1(int k) {
  for (int i = k; i > 0; i--) {
    for (int p = 0; p < k - i; p++) {
      cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
      cout << j % 10 << " ";
    }
    cout << endl;
  }
}
void printTriangle2(int k) {
  for (int i = k; i > 0; i--) {
    for (int p = 0; p < k - i; p++) {
      cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
      cout << j % 10 << " ";
    }
    for (int j = i; j >= 1; j--) {
      cout << j % 10 << " ";
    }
    for (int p = 0; p < k - i; p++) {
      cout << "  ";
    }
    cout << endl;
  }
}
int main() {
  cout.sync_with_stdio(0);
  cout.tie(0);
  unsigned long long N, k;
  cin >>N>> k;
  if (N % 2 + N % 3 == 0)
    printSquare(k);
  if (N % 2 == 1)
    printTriangle1(k);
  if (to_string(N).size() % 2 == 1)
    printTriangle2(k);
  return 0;
}
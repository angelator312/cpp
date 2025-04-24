#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
const int N = 1e8 + 1;
const int P = 255 + 1;
int n, p;
int moveCh(const int &a, const char &b, const char &c ) {
  cout << "Move disk #" << a << " from "<<b<<" to "<<c << endl;
  return 0;
}
LL rekursia(const int &a,char F,char T,char H) {
  if (a == 1)
  {
    moveCh(1,F,T);
    return 1;
  }
  return rekursia(a - 1,F,H,T) + moveCh(a,F,T) + rekursia(a - 1,H,T,F) + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  cerr << rekursia(n,'A','C','B') << endl;
}
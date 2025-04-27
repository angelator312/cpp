#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 2;
int n, sledSum = 0;
int redica[N];
inline void read() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> redica[i];
    sledSum += redica[i];
  }
  sort(redica, redica + n, greater<>());
}
int main() {
  read();
  int i = 0;
  for (; i < n && i < sledSum; ++i) {
    sledSum -= redica[i];
  }
  cout << i << endl;
}
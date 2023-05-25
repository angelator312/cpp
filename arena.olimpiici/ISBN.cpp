#include <iostream>
using namespace std;
int main() {
  string n;
  cin >> n;
  int j = 0, sum = 0, z, zi;
  for (int i = 10; i >= 1; i--) {
    if (n[j] == '*') {
      z = j;
      zi = i;
      j++;
      continue;
    } else if (n[j] == 'X') {
      sum += 10 * i;
    } else {
      sum += (n[j] - '0') * i;
    }
    j++;
  }
  int out=0;
  for (int i = 0; i <= 10; i++) {
    if ((sum + i * zi) % 11 == 0) {
      out = i;
    }
  }
  if (out == 10)
    cout << "X" << endl;
  else
    cout << out << endl;
  return 0;
}

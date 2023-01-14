#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<short> ds;
  long n;
  cin >> n;
  for (long i = 0, d = 1;; d = d * 10, i++) {
    if (n / d == 0) {
      break;
    }
    ds.push_back(n / d % 10);
  }
  vector<short> rds = vector<short>(ds.rbegin(), ds.rend());
//   for (int i = 0; i < rds.size(); i++) {
//     cout << rds[i] << endl;
//   }
  int ri = -1, r = 0;
  for (int i = 0; i < rds.size(); i++) {
    int x1 = 0, x2 = 0;
    for (int j = 0; j < i; j++) {
      x1 += rds[j];
    }
    for (int j = i; j < rds.size(); j++) {
      x2 += rds[j];
    }
    if (x1 == x2) {
      ri = i;
      r = rds[i-1];
      break;
    }
  }
  cout << r << " ";
  if (ri != -1) {
    cout << ri << endl;
  }
  return 0;
}
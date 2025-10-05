#include "permutation.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  cerr << "encoding\n";
  vector<int> enc = encode(p);
  int cntNeg = 0;
  for (auto x : enc)
    cntNeg += (x == -1);

  cerr << "decoding\n";
  vector<int> dec = decode(enc);

  if (dec == p) {
    cout << "OK with ";
  } else {
    cout << "WA with ";
  }
  cout << cntNeg << " -1s." << endl;
}

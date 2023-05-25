#include <iostream>
using namespace std;

short nac[3002][30002]{};
int main() {
  int n, br = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int e, e1, e2;
    cin >> e >> e1 >> e2;
    for (int j = e; j <= e1; j++) {
      nac[e2][j]++;
    }
  }
  for (int i = 1; i < 3002; i++) {
    for (int j = 1; j < 30002; j++) {
      br = max(short(br), nac[i][j]);
    }
  }
  cout<<br<<endl;
  return 0;
}
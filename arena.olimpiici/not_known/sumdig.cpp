#include <iostream>
#include <math.h>
using namespace std;
int sm(int e,int a, int k) {
  int sum = 0;
  for (int i = 0; i < k; i++) {
    int e2 = e - i;
    if(a>e2)return 0;
    while (e2 > 0) {
      sum += e2 % 10;
      e2 /= 10;
    }
  }
  return sum;
}
int main() {
  int a, b, k, mS = 0;
  cin >> a >> b >> k;
  int e = b, sum = sm(b,a,k), digs = 0;
  while (e > 0) {
    e /= 10;
    digs++;
  }
  for (int i = 2; i <= digs; i++) {
    string ch = to_string(b);
    int n = ch.size();
    int e = n - i;
    for (int j = 1; j < i; j++) {
      ch[n - j] = '9';
    }
    if (ch[e] == '0') {
      continue;
    } else {
      ch[e] = ch[e] - 1;
    }
    sum=max(sum,sm(stoi(ch), a,k));
    // cout << ch << endl;
  }

  // for (int i = 2; i <= digs; i++) {
  //   int p = pow(10, i - 1), sumF = sm(b - p, k);
  //   sum = max(sum, sumF);
  //   // cout<<sumF<<":sumF i:"<<i<<" ch:"<<b-p<<" p:"<<p<<endl;
  // }

  cout << sum << endl;
}
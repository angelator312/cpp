#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long n;
  cin >> n;
  const int N = n + 2;
//   int len = 0, mainLen = 0;
  int a[N]; // Pravilo na Lupov
  int b[N]{}; // Pravilo na Lupov
  for (long long i = 0; i < n; i++) {
    int e;
    cin >> e;
    a[i] = e;
  }
  for (long long i = n - 1; i > 0; i--) {
    // cout << i << endl;
    if (a[i - 1] < a[i]) {
      b[i - 1] = b[i] + 1;
    } else
      b[i - 1] = b[i];
  }
  cout << b[0] +1<< endl; // 1 i samoto chislo
  return 0;
}
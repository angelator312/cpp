#include <iostream>
using namespace std;
using pI = pair<int, int>;
const int N = 1e5 + 2;
const int A = N;
int n, br;
int redica[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> redica[i];
  }
  for (int i = 1; i <= n; ++i) {
    if(redica[i]!=i)++br;
  }
  cout << br << endl;
}
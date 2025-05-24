#include <iostream>
#include <vector>
using namespace std;
using LL = long long;
vector<int> sum;
int main() {
  int i = 0;
  int n;
  cin >> n;
  sum.resize(2 * n + 3);
  int arr[n][n];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      sum[i] += arr[i][j];
    for (int j = 0; j < n; ++j)
      sum[i + n] += arr[j][i];
  }

  int n2 = n * 2;
  for (int i = 0; i < n; ++i)
    sum[n2] += arr[i][i];
  ++n2;
  for (int i = 0; i < n; ++i)
    sum[n2] += arr[i][(n-i)-1];
  // sum[7] = arr[0][2] + arr[1][1] + arr[2][0];
  int sumA = sum[0];
  for (int i = 1; i < 2 *n+2; ++i) {
    if (sumA != sum[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}
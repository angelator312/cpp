#include <iostream>
#include <vector>
using namespace std;
const int A = 7e4 + 1;
int count[A];
int n;
vector<int> a;
int sum = 0;
void Read() {
  cin >> n;
  a.resize(n);
  for (int &i : a)
    cin >> i;
  for (const int &i : a)
    sum += i;
}
int main() {
  Read();

  count[0] = 1;
  count[0] = true;
  for (int k = 1; k <= n; k++) {
    for (int x = sum; x >= 0; x--) {
      if (count[x])
        ++count[x + a[k-1]];
    }
  }
  int biggest = -1, times = -1, broiSumi = 0;
  for (int x = 1; x <= sum; x++) {
    if (!count[x])
      continue;
    if (count[x] >= times)
      biggest = x;
    if (count[x] > times)
      times = x;
    ++broiSumi;
  }
  cout << broiSumi << endl;
  cout << biggest << " " << times << endl;
  cout << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  vector<int> a;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    if (e % 2 == 0)
      a.push_back(e);
  }
  int b = a.size();
  if (b % 2 == 0)
    cout << a[b / 2-1] << endl;
  else
    cout << a[b / 2] << endl;
  return 0;
}

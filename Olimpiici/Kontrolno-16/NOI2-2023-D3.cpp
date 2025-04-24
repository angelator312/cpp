// #include
#include <iostream>
#include <vector>
// using
using namespace std;
using LL = long long;
using pI = pair<int, int>;
// const
const int A = 1e5 + 2;
const int N = 1e5 + 2;
const int T = 1e5 + 2;
// arrays
vector<int> v[A];
int n, t;
int arr[N];
// functions
void init() {}
void search(int nomer) {
  const int e = arr[nomer];
  const int sz = v[e].size();
  for (int ind = 0; ind < sz; ind++) {
    if (v[e][ind] == nomer) {
      if (ind == 0)
        cout << 0 << " ";
      else
        cout << v[e][ind - 1] << " ";
      if (ind == sz - 1)
        cout << 0 << endl;
      else
        cout << v[e][ind + 1] << endl;
    }
  }
}
// main function
int main() {
  init();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    v[arr[i]].push_back(i);
  }
  cin >> t;
  int e;
  for (int i = 0; i < t; i++) {
    cin >> e;
    search(e);
  }
}

/* Примери:
8
2 4 5 4 4 2 7 4
3
1 8 4
*/

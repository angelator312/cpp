#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 2;
int redica[N];
int cnt[N];
int min_dev[N];
vector<int> pr;
void reshEratosten() {
  for (int i = 2; i < N; ++i) {
    if (!min_dev[i])
      continue;
    pr.push_back(i);
    for (int j = i; j < N; j += i) {
      if (!min_dev[j]) {
        min_dev[j] = i;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, n2 = 0, a, otg = 0;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    if (a % m == 0) {
      redica[n2] = a;
      while (min_dev[a]) {
        ++cnt[min_dev[a]];
        a /= min_dev[a];
      }
      ++n2;
    }
  }
  for (int x = n; x > 0; --x)
    cnt[x] = cnt[x] * (cnt[x] - 1) * (cnt[x] - 2) / 6;
  int ptr_a = 0;
  for (int x = n; x > 0; --x) {
    ptr_a=0;
    while (pr[ptr_a]<x) {
      cnt[ptr_a]-= cnt[pr[ptr_a]*x];
    }
  }

  cout << otg << endl;
  return 0;
}
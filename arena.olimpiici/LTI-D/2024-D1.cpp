#include <bitset>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const int N = 1e4;
const int N2 = 1e4 + 1;
const size_t NN = N * N + 2;
int n, m;
vector<int> edges[N + 2];
bitset<NN> matrix;
int main() {
  cin >> n >> m;
  for (int i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
    matrix[a * N2 + b] = true;
    matrix[b * N2 + a] = true;
  }
  for (int i = 1; i <= n; ++i) {
    for (auto e : edges[i]) {
      for (auto e2 : edges[i]) {
        if (e == e2)
          continue;
        if (!matrix[e * N2 + e2]) {
          // cerr<<e<<" "<<e2<<endl;
          cout << "NO" << endl;
          return 0;
        }
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
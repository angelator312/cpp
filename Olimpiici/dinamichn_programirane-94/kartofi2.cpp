#include <iostream>
#include <stack>
using namespace std;
const int N = 1501;
const int M = 1501;
long long memorization[N][M];
int matrix[N][M];
bool matrix2[N][M]; //<false;^true
int n, m;

long long f(int i, int j) {
  if (i < 0 || j < 0)
    return 0;
  if (memorization[i][j])
    return memorization[i][j];
  return memorization[i][j] = max(f(i - 1, j), f(i, j - 1)) + matrix[i][j];
}
void read() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
    }
  }
}

int main() {
  read();
  f(n - 1, m - 1);
  stack<pair<int, int>> st;
  {
    int i = n - 1, j = m - 1;
    while (i > 0 || j > 0) {
      st.push({i, j});
        if (f(i, j)-matrix[i][j] == f(i - 1, j))
          --i;
        else
          --j;
      // }
    }
  }
  cout << 1 << " " << 1 << endl;
  //*
  while (!st.empty()) {
    pair<int, int> e = st.top();
    st.pop();
    cout << e.first + 1 << " " << e.second + 1 << endl;
  }
  //*/
  return 0;
}

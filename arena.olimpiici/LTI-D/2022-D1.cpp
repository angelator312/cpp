#include <iostream>
using namespace std;
char mravki[N];
const int N = 1e5 + 2;
int n, m;
int virtLeft(const char &a) {
  switch (a) {
  case 'u':
    return 1;
    break;

  case 'd':
    return 1;
    break;

  case 'r':
    return 2;
    break;

  default:
    break;
  }
  return 0;
}
void read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m;
  for (int i = 0, e; i < n; ++i) {
    cin >> e >> mravki[e];
  }
  mravki[0] = "l";
  mravki[n + 1] = "r";
}
int main(int argc, char const *argv[]) {
  read();

  return 0;
}

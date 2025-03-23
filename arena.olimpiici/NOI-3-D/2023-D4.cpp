#include <iostream>
#include <vector>
using namespace std;
const int OTMESTVANE = 3e5;
const int A = 1e5 + 1;
const int N = 5e3;
int n, el, br;
bool cnt[OTMESTVANE + A + A];
int redica[N];
vector<int> v;
void init() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> el;
    redica[i] = el;
    for (int j=0;j<i;++j)
      if (cnt[OTMESTVANE+(el - redica[j])]) {
        ++br;
        break;
      }
    for (int j = 0; j <= i; ++j) {
      int ind = OTMESTVANE + el + redica[j];
      if (!cnt[ind]) {
        cnt[ind] = 1;
      }
    }
  }
}

int main() {
  init();
  cout << br << endl;
  return 0;
}

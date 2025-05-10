#include <iostream>
using namespace std;
using LL = __int128_t;
const int N = 1e7 + 2;
int n;
LL boxers_prefix[N];
LL sum;
int boxers[N];
int minR[N];
long long k;
inline void Init() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> boxers[i];
    boxers_prefix[i] += boxers[i];
  }
  for (int i = 1; i <= n; ++i) {
    boxers_prefix[i] += boxers_prefix[i - 1];
  }
}
inline void PrintOut() {
  long long br = 0;
  for (int i = 1; i < n; ++i) {
    br += (n - minR[i]);
    // cerr << i << " " << (n - minR[i]) + 2 << endl;
  }
  br += (n - 1) * 2;
  cout << br << endl;
}
/**
 *
 * @param from is the start of the sum for action of the boxer
 * @param to is the end of the sum for action of the boxer
 * @param who is the index of the boxer
 */
inline LL action(int from, int to, int who) {
  return boxers[who] * (boxers_prefix[to] - boxers_prefix[from - 1]);
}
int main() {
  Init();
  int r = 1;
  for (int l = 1; l < n; ++l) {
    // cerr << (long long)sum << "<-l " << l << endl;
    while (r <= n + 1 && sum < k) {
      sum += action(l, r - 1, r);
      // cerr << (long long)sum << "<-" << r << endl;
      ++r;
    }
    if (sum < k) {
      minR[l] = n + 2;
      r = n;
      continue;
    }
    // cerr << l << "->" << r << " " << (long long)sum << endl;
    minR[l] = r;
    sum -= action(l + 1, r - 1, l);
  }
  PrintOut();
  return 0;
}
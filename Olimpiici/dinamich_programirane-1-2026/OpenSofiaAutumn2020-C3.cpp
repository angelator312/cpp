#include <iostream>
#include <vector>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê
using namespace std;
using num = int;
using idx_t = int;
const int MAX_BROI_KULI = 500;

num broiKuli, maxPari;
num heights1[MAX_BROI_KULI];
num heights2[MAX_BROI_KULI];

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> broiKuli >> maxPari;
  for (idx_t i = 1; i <= broiKuli; ++i)
    cin >> heights1[i] >> heights2[i];
}

int main() {
  Read();
  vector<num> old_dp(maxPari + 1);
  old_dp[0] = 0;
  for (idx_t i = 1; i <= broiKuli; ++i) {
    vector<num> new_dp(maxPari + 1);
    for (idx_t j = 0; j <= maxPari; ++j) {
        //TODO: Think about here
    }
  }
  num mx = -1;
  for (idx_t j = 0; j <= maxPari; ++j)
    mx = min(mx, old_dp[j]);
  printf("%d\n", mx);
  return 0;
}

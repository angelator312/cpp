#include <ios>
#include <iostream>

using namespace std;
using num = long long;

const long long R = 1e14;

num n, time_to_next_paner, time_to_get_paner;

inline bool IsPossible(const num &most_used_time) noexcept {
  num br = 0, time_to_now = time_to_next_paner;
  while (time_to_now <= most_used_time && br < n) {
    br += (most_used_time - time_to_now) / time_to_get_paner + 1;
    time_to_now += time_to_next_paner;
  }
  return br >= n;
}

inline void SolveRequest() noexcept {
  cin >> n >> time_to_next_paner >> time_to_get_paner;
  num left_pointer = 0, right_pointer = R, ans = -1;
  while (left_pointer <= right_pointer) {
    num mid_pointer = left_pointer + (right_pointer - left_pointer) / 2;
    if (IsPossible(mid_pointer)) {
      right_pointer = mid_pointer - 1;
      ans = mid_pointer;
    } else {
      left_pointer = mid_pointer + 1;
    }
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  num t;
  cin >> t;
  for (num i = 0; i < t; ++i)
    SolveRequest();
  return 0;
}

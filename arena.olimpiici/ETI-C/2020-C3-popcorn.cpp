//100
#include <iostream>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif

using namespace std;
using num = long long;
using idx_t = int;
const long long MAX_END = 1e10;
const int MAX_PACKETS_SIZE = 1e5 + 1;

size_t popcornsForSec, packetsSize, teamSize;

int packets[MAX_PACKETS_SIZE];

bool ok(const num secs) {
  const num popcorn = secs * popcornsForSec;
  idx_t playersEnded = 0, i = 0;
  while (i < packetsSize) {
    num sum = 0;
    while (i < packetsSize) {
      if (sum + packets[i] > popcorn)
        break;
      sum += packets[i];
      ++i;
    }
    ++playersEnded;
    if (playersEnded > teamSize)
      return false;
  }
  if (playersEnded > teamSize)
    return false;
  return true;
}

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> packetsSize >> teamSize >> popcornsForSec;
  for (idx_t i = 0; i < packetsSize; ++i)
    cin >> packets[i];
}

int main() {
  Read();
  long long start = 0, end = MAX_END, ans = 0;

  while (start <= end) {
    long long mid = start + (end - start) / 2;
    eprintf("Mid:%lld\n", mid);
    if (ok(mid)) {
      end = mid - 1;
      ans = mid;
    } else
      start = mid + 1;
  }
  printf("%lld\n", ans);
  return 0;
}

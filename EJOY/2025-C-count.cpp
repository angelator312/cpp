#include <algorithm>
#include <cstdio>
#include <ios>
#include <iostream>
#if 0
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
using namespace std;

using num = long long;
using idx_t = int;
using out_t = int;

const int MOD = 1e9 + 7;

string maxNumber;
idx_t maxNumberSize;
// a>=b
inline bool isBiggerOrEqual(const string &a, const idx_t &szOfA,
                            const string &b, const idx_t &szOfB) noexcept {
  if (szOfA < szOfB)
    return false;
  if (szOfA > szOfB)
    return true;
  return a >= b;
}
// a>b
inline bool isBigger(const string &a, const idx_t &szOfA, const string &b,
                     const idx_t &szOfB) noexcept {
  if (szOfA < szOfB)
    return false;
  if (szOfA > szOfB)
    return true;
  return a > b;
}

inline bool isMaxNumberBiggerOrEqualToNumber(const string &doSegaNumber,
                                             const idx_t &szOfDoSegaNumber) {
  return isBiggerOrEqual(maxNumber, maxNumberSize, doSegaNumber,
                         szOfDoSegaNumber);
}

inline bool isBiggerThanTheMaxNumber(const string &doSegaNumber,
                                     const idx_t &szOfDoSegaNumber) noexcept {
  return isBigger(doSegaNumber, szOfDoSegaNumber, maxNumber, maxNumberSize);
}

inline out_t DP(string &doSegaNumber, idx_t szOfDoSegaNumber,
                const int &sumToMake) noexcept {
  out_t out = 0;
  eprintf("%s-%d-%d\n", doSegaNumber.c_str(), szOfDoSegaNumber,
          isMaxNumberBiggerOrEqualToNumber(doSegaNumber, szOfDoSegaNumber));
  if (sumToMake == 0) {
    eprintf("right:%s\n", doSegaNumber.c_str());
    // calculateWithLast0(doSegaNumber, szOfDoSegaNumber)
    if (isMaxNumberBiggerOrEqualToNumber(doSegaNumber, szOfDoSegaNumber)) {
      doSegaNumber.push_back('0');
      out = 1 + DP(doSegaNumber, szOfDoSegaNumber + 1, sumToMake);
      doSegaNumber.pop_back();
      return out;
    }
    return 0;
  }
  ++szOfDoSegaNumber;
  if (isBiggerThanTheMaxNumber(doSegaNumber + '0', szOfDoSegaNumber))
    return 0;
  short i = 0;
  if (szOfDoSegaNumber == 1)
    i = 1;
  for (; i <= min(9, sumToMake); ++i) {
    doSegaNumber.push_back(char(i + '0'));
    out = (out + DP(doSegaNumber, szOfDoSegaNumber, sumToMake - i)) % MOD;
    doSegaNumber.pop_back();
  }
  return out;
}
string startDPString = "";
int sumOnRequest;
inline out_t SolveRequest() noexcept {
  cin >> maxNumber >> sumOnRequest;
  maxNumberSize = maxNumber.size();

  return DP(startDPString, 0, sumOnRequest);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  idx_t tests;
  cin >> tests;
  while (tests--)
    printf("%d\n", SolveRequest());
}

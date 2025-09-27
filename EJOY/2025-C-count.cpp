#include <algorithm>
#include <cstdio>
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
bool isBiggerOrEqual(const string &a, const idx_t &szOfA, const string &b,
                     const idx_t &szOfB) {
  if (szOfA < szOfB)
    return false;
  if (szOfA > szOfB)
    return true;
  return a >= b;
}

bool isBigger(const string &a, const idx_t &szOfA, const string &b,
              const idx_t &szOfB) {
  if (szOfA < szOfB)
    return false;
  if (szOfA > szOfB)
    return true;
  return a > b;
}

bool isMaxNumberBiggerOrEqualToNumber(const string &doSegaNumber,
                                      const idx_t &szOfDoSegaNumber) {
  return isBiggerOrEqual(maxNumber, maxNumberSize, doSegaNumber,
                         szOfDoSegaNumber);
}

bool isBiggerThanTheMaxNumber(const string &doSegaNumber,
                              const idx_t &szOfDoSegaNumber) {
  return isBigger(doSegaNumber, szOfDoSegaNumber, maxNumber, maxNumberSize);
}
// Calculate things like 10,100,200,2000...
// out_t calculateWithLast0(string doSegaNumber, idx_t szOfDoSegaNumber) {
//   out_t out = 0;
//   for (int i = 0; i < szOfDoSegaNumber - szOfDoSegaNumber; ++i) {
//     doSegaNumber.push_back('0');
//     if (isMaxNumberBiggerOrEqualToNumber(doSegaNumber, szOfDoSegaNumber))
//       ++out;
//     else
//       break;
//   }
//   return out;
// }

out_t DP(string doSegaNumber, idx_t szOfDoSegaNumber, num sumToMake) {
  out_t out = 0;
  eprintf("%s-%d-%d\n", doSegaNumber.c_str(), szOfDoSegaNumber,
          isMaxNumberBiggerOrEqualToNumber(doSegaNumber, szOfDoSegaNumber));
  if (sumToMake == 0) {
    eprintf("right:%s\n", doSegaNumber.c_str());
    // calculateWithLast0(doSegaNumber, szOfDoSegaNumber)
    if (isMaxNumberBiggerOrEqualToNumber(doSegaNumber, szOfDoSegaNumber)) {
      doSegaNumber.push_back('0');
      return 1 + DP(doSegaNumber, szOfDoSegaNumber + 1, sumToMake);
    }
    return 0;
  }
  ++szOfDoSegaNumber;
  if (isBiggerThanTheMaxNumber(doSegaNumber + '0', szOfDoSegaNumber))
    return 0;
  short i = 0;
  if (szOfDoSegaNumber == 1)
    i = 1;
  for (; i <= min(9LL, sumToMake); ++i) {
    doSegaNumber.push_back(char(i + '0'));
    out = (out + DP(doSegaNumber, szOfDoSegaNumber, sumToMake - i)) % MOD;
    doSegaNumber.pop_back();
  }
  return out;
}

out_t SolveRequest() {
  num sum;
  cin >> maxNumber >> sum;
  maxNumberSize = maxNumber.size();
  // eprintf("%d\n", isBiggerThanTheMaxNumber("123457", 6));
  // return 0;
  return DP("", 0, sum);
}

int main() { printf("%d\n", SolveRequest()); }

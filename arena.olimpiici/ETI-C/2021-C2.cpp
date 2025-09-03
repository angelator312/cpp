#include <iostream>
using namespace std;

using num = int;
using idx_t = int;

const int MAX_SIZE_OF_PRICES = 5e5 + 2;

num prices[MAX_SIZE_OF_PRICES];

num sizeOfPrices, countOfTalks;
//<price below zero,price bigger than zero>
pair<num, num> DP(idx_t idx) {
  if (idx >= sizeOfPrices)
    return {0, 0};
  pair<num, num> previousDP = DP(idx + 1);
  if (prices[idx] < 0)
    previousDP.first += prices[idx];
  else
    previousDP.second += prices[idx];
  if (previousDP.first + previousDP.second >
      -previousDP.first - previousDP.second) {
    previousDP.second *= -1;
    previousDP.first *= -1;
  }
  return previousDP;
}

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> sizeOfPrices >> countOfTalks;
  for (idx_t i = 0; i < sizeOfPrices; ++i)
    cin >> prices[i];
}

int main() {
  Read();
  pair<num, num> out = DP(0);
  cout << out.first + out.second << endl;
  return 0;
}

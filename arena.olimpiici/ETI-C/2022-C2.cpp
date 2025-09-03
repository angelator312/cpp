#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

using num = int;
using big_num = long long;
using idx_t = int;

const int N = 1e5 + 2;

big_num countOfGrounds, countOfRequests, fuelCostForOneMeter;
set<pair<num, num>> grounds;
big_num posOnGround, e2;

void Read() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> countOfGrounds >> countOfRequests >> fuelCostForOneMeter;
  for (idx_t i = 0; i < countOfGrounds; ++i) {
    cin >> posOnGround >> e2;
    grounds.insert({posOnGround, e2});
  }
}
big_num bestFuel;

big_num CalculateBestFuelFromGroundIterator(
    _Rb_tree_const_iterator<std::pair<int, int>> ground_it) {
  return abs(ground_it->first - posOnGround) * fuelCostForOneMeter +
         ground_it->second;
}
_Rb_tree_const_iterator<std::pair<int, int>> end_it, ground_it;

void PlusPlusEndIterator() {
  if (end_it != grounds.end())
    ++end_it;
}

void MinusMinusGroundIterator() {
  if (ground_it != grounds.begin())
    --ground_it;
}

void SolveRequest() {
  cin >> posOnGround;
  ground_it = grounds.lower_bound({posOnGround, 0});
  if (ground_it == grounds.end())
    ground_it = grounds.begin();

  pair<num, num> ground = *ground_it;
  bestFuel = CalculateBestFuelFromGroundIterator(ground_it);
  // cerr << ground.first << " " << ground.second << endl;

  end_it = ground_it;

  ++end_it;
  for (idx_t i = 0; i < 20; ++i)
    PlusPlusEndIterator();

  ground_it = grounds.begin();
  // for (idx_t i = 0; i < 50; ++i)
  //   MinusMinusGroundIterator();

  for (; ground_it != end_it; ++ground_it) {
    // ground = *ground_it;
    // cerr << ground.first << " " << ground.second << endl;
    bestFuel = min(bestFuel, CalculateBestFuelFromGroundIterator(ground_it));
  }
  cout << bestFuel << endl;
}

int main() {
  Read();
  for (idx_t i = 0; i < countOfRequests; ++i)
    SolveRequest();
  return 0;
}

#include "grader67.h"
#include <climits>
#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> ans = solve(n);
  int sum = 0;
  double out = 0;
  unordered_set<int> arr;
  int mx = 0, mn = INT_MAX;
  for (int e : ans) {
    arr.insert(e);
    sum = (sum + e) % n;
    mx = max(mx, e);
    mn = min(mn, e);
  }
  if (arr.size() > 1)
    out += 0.15;

  if (sum == 0)
    out += 0.25;

  if (abs(mn - mx) <= 2)
    out += 0.60;

  cout << out << endl;
}

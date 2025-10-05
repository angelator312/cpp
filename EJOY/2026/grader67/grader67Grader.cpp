#include "grader67.h"
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
  for (int e : ans) {
    arr.insert(e);
    sum = (sum + e) % n;
  }
  if (arr.size() > 1)
    out += 0.15;
  else
    out += 0.60;
  if (sum == 0)
    out += 0.25;
  cout << out << endl;
}

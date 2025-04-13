#include <algorithm>
#include <array>
#include <iostream>
#include <vector>
using namespace std;
using pI = pair<int, int>;
using typ = array<int, 3>;
const int N = 3e5 + 2;        // Lupi pravilo
const int A = 1e5 + 2, Q = N; // Lupi pravilo
const int POINT = 2;
const int LEFT = 1;
const int RIGHT = 3;
int out_intervals[Q];
int out_points[N];
vector<typ> all;

int main() {
  int n, q, max_number = 0;
  cin >> n >> q;
  for (int i = 0, e; i < n; i++) {
    cin >> e;
    all.push_back({e, POINT, i});
  }
  for (int i = 0, e; i < q; i++) {
    cin >> e;
    all.push_back({e, LEFT, i});
  }
  for (int i = 0, e; i < q; i++) {
    cin >> e;
    all.push_back({e, RIGHT, i});
  }
  sort(all.begin(), all.end());
  int points = 0, br_intervals = 0;
  for (const auto e : all) {
    if (e[1] == POINT) {
      out_points[e[2]] = br_intervals;
      ++points;
    } else if (e[1] == LEFT) {
      ++br_intervals;
      out_intervals[e[2]] = -points;
    } else if (e[1] == RIGHT) {
      --br_intervals;
      out_intervals[e[2]] += points;
    }
  }

  for (int i = 0; i < n; ++i)
    cout << out_points[i] << " ";
  cout << endl;
  for (int i = 0; i < q; ++i)
    cout << out_intervals[i] << " ";
  cout << endl;
  return 0;
}
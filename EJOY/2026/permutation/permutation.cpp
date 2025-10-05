#include "permutation.h"
#include <cstdlib>
#include <vector>
using namespace std;
vector<int> encode(const vector<int> p) {
  vector<int> p2;
  int cnt = 0;
  p2.push_back(p[0]);
  for (int i = 1; i < p.size(); ++i) {
    if (p[i] == p[i - 1] + 1) {
      ++cnt;
      p2.push_back(-1);
    } else
      p2.push_back(p[i]);
  }
  if (cnt == 0) {
    for (int &i : p2)
      if (i == 1)
        i = -1;
    if (p2[0] > 0)
      p2[0] *= -1;
  }
  return p2;
}
vector<int> decode(vector<int> p) {

  int cnt = 0;
  for (int i = 1; i < p.size(); ++i)
    if (p[i] == -1) {
      ++cnt;
      if (p[0] > 0)
        p[i] = 1 + p[i - 1];
      else
        p[i] = 1;
    }
  if (cnt == 0)
    p[0] = 1;
  p[0] = abs(p[0]);
  return p;
}

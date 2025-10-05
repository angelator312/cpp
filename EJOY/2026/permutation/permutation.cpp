#include "permutation.h"
#include <bits/stdc++.h>
using namespace std;
vector<int> encode(vector<int> p) {
  for (int i = 0; i < p.size(); ++i)
    if (p[i] == i + 1)
      p[i] = -1;
  return p;
}
vector<int> decode(vector<int> p) {
  for (int i = 0; i < p.size(); ++i)
    if (p[i] == -1)
      p[i] = 1 + i;
  return p;
}

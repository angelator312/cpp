// 67 points
#include "testove.h"
#include <algorithm>
#include <vector>
#if 1
#define eprintf(args...) fprintf(stderr, args)
#else
#define eprintf(args...)
#endif
// ₳₦₲ɆⱠ₳₮ØⱤ312 𝕨𝕒𝕤 hêrê
using namespace std;

using num = int;
using idx_t = int;
using tree_el = pair<int, int>;
using tree_t = vector<tree_el>;

vector<num> heights;
vector<num> originalHeights;

bool Compare(const tree_el &a, const tree_el &b) { return a < b; }

vector<tree_t> generate(int verticesCount, int treesCount) {
  vector<tree_t> trees;
  vector<num> perm;
  for (int i = 1; i <= verticesCount; ++i)
    perm.push_back(i);
  tree_t tree;
  for (int i = 1; i < verticesCount; ++i)
    tree.push_back({i, i + 1});
  num height = verticesCount - 1;
  while (treesCount--) {
    originalHeights.push_back(height);
    trees.push_back(tree);
    if (!next_permutation(tree.begin(), tree.end(), Compare)) {
      tree.pop_back();
    }
  }
  heights = originalHeights;
  return trees;
}

int query(int i, int r) {
  int mx = 0;
  for (; i <= r; ++i)
    mx = max(mx, heights[i]);
  return mx;
}
void remove(int ind) { heights[ind] = 0; }
void add(int ind) { heights[ind] = originalHeights[ind]; }

/*
Test1
4 1 5
0 0 0
2 0
0 0 0
1 0
0 0 0
 */

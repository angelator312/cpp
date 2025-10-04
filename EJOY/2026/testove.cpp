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
using tree_t = vector<std::pair<int, int>>;

vector<num> heights;
vector<num> originalHeights;

vector<tree_t> generate(int verticesCount, int treesCount) {
  vector<tree_t> trees;
  vector<num> perm;
  for (int i = 1; i <= verticesCount; ++i)
    perm.push_back(i);
  while (treesCount--) {
    tree_t tree;
    for (int i = 0; i < perm.size() - 1; ++i)
      tree.push_back({perm[i], perm[i + 1]});
    originalHeights.push_back(perm.size() - 1);
    trees.push_back(tree);
    if (!next_permutation(perm.begin(), perm.end())) {
      perm.clear();
      for (int i = 1; i <= perm.size() - 1; ++i)
        perm.push_back(i);
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

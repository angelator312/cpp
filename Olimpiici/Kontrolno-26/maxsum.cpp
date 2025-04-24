#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int N = 2e5 + 2;

int redica[N];
int redica2[N];
multiset<int> sorted;
int main() {
  int n, k;
  scanf("%d ", &n);
  scanf("%d ", &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d ", &redica[i]);
  }
  printf("first iteration\n");
  for (int i = 0; i < n; i++) {
    scanf("%d ", &redica2[i]);
    for (int j = 0; j < n; ++j) {
      sorted.insert(redica2[i] + redica[j]);
    }
  }
  auto it = sorted.begin();
  for (int i = 1; i < k; ++k)
    ++it;

  printf("%d", *it);
  printf("\n");
}
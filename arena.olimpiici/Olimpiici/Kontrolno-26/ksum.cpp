#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 2e5 + 2;

int redica[N];
int redica2[N];
vector<int> sorted;
int main() {
  int n, k;
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &redica[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &redica2[i]);
  }
  sort(redica, redica + n);
  sort(redica2, redica2 + n);
  int l=0,r=n,ans=n;
  while(l<=r)
  {
    
  }
  printf("%d", sorted[k - 1]);
  printf("\n");
}
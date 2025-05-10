#include <stdio.h>
#define endl "\n"
// int usedLighting[] = {6, 2, 5, 5, 4, 5, 6, 4, 7, 6};
int main() {
  int n;
  scanf("%d", &n);
  if (n < 2) {
    printf("-1\n");
    return 0;
  }
  if (n % 2 == 0)
    printf("1");
  else
    printf("7");
  n >>= 1;
  //   --n;
  //   while (n--)
  while (--n)
    printf("1");
  printf(endl);
}

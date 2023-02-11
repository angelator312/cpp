#include <iostream>

using namespace std;

const int MAX_SBOR = 50000;
int main() {
  int n;
  cin >> n;
  int a[n],sbors[MAX_SBOR],p;
  for (int i = 0; i < MAX_SBOR; i++)
    sbors[i] =0;
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
        sbors[a[i]+a[j]]++:
  }
  
  return 0;
}
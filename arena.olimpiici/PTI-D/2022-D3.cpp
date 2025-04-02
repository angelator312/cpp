#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5+3;
int n;
int redica[N];
int redica2[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i)
  cin >> redica[i];
  sort(redica, redica + n);
  for (int i = 0; i < n; ++i)redica2[i]=-1;
  int szvSI3=-1;
  // свързваме двойките при най-добра 2-ка {0,1}
  int suma=redica[0]+redica[1];
  for(int i=2;i<n;++i)
  {
    if(redica2[i])continue;
    for (int j = i+1; j < n; ++j) {
        if(redica2[j])continue;
        if(redica[i]+redica[j]>=suma)
        {
            redica2[j]=i;
            redica2[i]=j;
            break;
        }
    }
    if(redica2[i]==-1)
  }
  for(int i=1;i<=n-2;++i)
  {
    //{i,i+1}

  }
}
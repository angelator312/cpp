#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
#if 1
#define P(a) cout << a << " "
#else
#define P
#endif
using namespace std;
int a[3], b[3];
bool comp(int i,int j)
{
    return a[i]>=a[j] &&b[i]>=b[j];
}
int main()
{
    for(int i=0;i<3;i++)
        cin >> a[i] >> b[i];
    int p[3]={0,1,2};
    sort(p,p+3,comp);
    for (int i = 0; i < 3; i++)
    {
        P(p[i]+1);
    }
    cout<<endl;
   return 0;
}
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    int mInt=100002,mIndex=0;
    int k=0,m=0,sum=0;
    int e,i=1;
    cin>>m>>k;
    while (cin>>e)
    {
        if (e%2==0 && sum<=k)
        {
            sum+=e;
        }
        
        if (abs(m-e)<=mInt)
        {
            mInt=abs(m-e);
            mIndex=i;
        }
        i++;
    }
    cout<<mIndex<<" "<<sum<<endl;
    return 0;
}
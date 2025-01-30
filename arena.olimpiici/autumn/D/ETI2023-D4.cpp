#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
using LL = long long;
const int N = 2e5+1;
const int MOD = 1e9+7;
const int MOD2 = 1e9+9;
LL a[N];
LL prefix[N];
LL prefixNormal[N];
LL sum=0;
LL sum2=0;

void plusSum(LL e)
{
    sum+=e;
    sum=sum%MOD;
}
void plusSum2(LL e)
{
    sum2+=e;
    sum2=sum2%MOD2;
}
void plusSumMain(int e,int e2)
{
    LL eL=prefix[e2]-prefix[e-1]-(e-1)*(prefixNormal[e2]-prefixNormal[e-1]);
    plusSum(eL);
    plusSum2(eL);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    for(LL i=1; i<=n; i++)
    {
        cin>>a[i];
        prefixNormal[i]=a[i]+prefixNormal[i-1];
        long long e=(a[i]*i);
        prefix[i]=prefix[i-1];
        prefix[i]+=e;
    }

    //for(int i=1; i<=n; i++)
    //    cout<<prefix[i]<<" "<<prefix2[i]<<endl;
    for(int i=0; i<q; i++)
    {
        int e,e2;
        cin>>e>>e2;
        plusSumMain(e,e2);
    }
    cout<<sum<<" "<<sum2<<endl;

    return 0;
}

/*
    5 3
    1 2 3 4 5
    1 5
    1 4
    1 3
*/

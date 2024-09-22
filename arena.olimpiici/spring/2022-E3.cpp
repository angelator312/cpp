#include <bits/stdc++.h>
using namespace std;
using LL=long long;

void dels(LL a,LL b)
{
    LL n=__gcd(a,b);
    cout<<1<<" "<<a<<" "<<b<<endl;
    for(LL i=2;i<=n;i++)
    {
        if(n%i==0)
            cout<<i<<" "<<a/i<<" "<<b/i<<endl;

    }
}


int main()
{
    cout.sync_with_stdio(0);
    cout.tie(0);

    LL a,b;
    cin >> a>>b;
    dels(a,b);
}
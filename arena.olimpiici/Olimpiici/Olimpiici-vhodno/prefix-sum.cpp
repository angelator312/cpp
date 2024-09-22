#include <bits/stdc++.h>
using namespace std;
const int N=1e5+1;

long long prefix[N];
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        long long e;
        cin>>e;
        prefix[i]=prefix[i-1]+e;
        // cout<<prefix[i]<<endl;
    }
    int k;
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        int e,e2;
        cin>>e>>e2;
        // cout<<prefix[e2]<<endl;
        // cout<<prefix[e-1]<<endl;
        cout<<prefix[e2]-prefix[e-1]<<endl;
    }
    
    return 0;
}
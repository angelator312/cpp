#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
#define endl "\n"
using namespace std;
using LL=long long;
const int A=5e3+2;
const int N=5e3+2;
vector<int> col[A];
vector<int> row[A];
int redica[N];
int redica2[N];
bitset<N> bits(0);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        cin>>redica[i];
        col[redica[i]].push_back(i);
    }
    for(int i=0;i<n;++i)
    {
        cin>>redica2[i];
        row[redica2[i]].push_back(i);
    }
    LL mxSum=0;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            mxSum+=min(redica[i],redica2[j]);
        }
    }
    int e=0;
    for(int i=0;i<m;++i)
    {
        e=redica[i];
        if(bits[e])continue;
        bits.set(e,true);
        sort(col[e].begin(),col[e].end());
    }

    int br=0;
    cout<<br<<" "<<mxSum<<endl;
    cout<<0<<endl;
    return 0;
}
/*
1
5
4 3 3 4 4
*/

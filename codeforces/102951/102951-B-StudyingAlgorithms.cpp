#include<iostream>
#include<algorithm>

using namespace std;
using LL=long long;
using pI=pair<int,int>;
const int N=1e8;
LL prefix[N];//divs
int n,q,mxI=0;
int l,r,v;
int main()
{
    cin>>n>>q;
    for(int i=0; i<n; ++i)
    {
        cin>>l>>r>>v;
        prefix[l]+=v;
        prefix[r]-=v;
        mxI=r+1;
        //cerr<<"l:"<<prefix[l]<<endl;
        //cerr<<"r:"<<prefix[r]<<endl;
    }
    for(int i=1; i<=mxI; ++i)
    {
        prefix[i]+=prefix[i-1];
    }
    cerr<<prefix[0]<<" ";
    for(int i=1; i<=mxI+5; ++i)
    {
        prefix[i]+=prefix[i-1];
        cerr<<prefix[i]<<" ";
    }
    cerr<<endl;
    for(int i=0; i<q; ++i)
    {
        cin>>l>>r;
        if(mxI<r)
        {
            r=mxI;
        }else --r;
        cout<<prefix[r]-prefix[--l]<<endl;
    }
}

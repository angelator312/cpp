#include<iostream>
using namespace std;
const int N=1e5+2;

int divs[N];

int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=0,l,r;i<q;++i)
    {
        cin>>l>>r;
        ++divs[l];
        --divs[r+1];
    }
    for(int i=1;i<=n;++i)
    {
        divs[i] +=divs[i-1];
        cout<<divs[i]<<" ";
    }
    cout<<"\n";
}
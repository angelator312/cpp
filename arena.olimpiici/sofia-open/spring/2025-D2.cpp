#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#define endl "\n"
using namespace std;
using LL=long long;
using pI=pair<int,int>;
const int A=1e6+2;
const int N=2e5+2;
int max_del[A];
int redica[N];
map<int,bool>izp;
void reshNaEratosten()
{
    for(int i=2;i<=A;++i)
    {
        if(max_del[i])continue;
        //cerr<<i<<" ";
        for(LL j=i;j<=A;j+=i)
        {
            max_del[j]=i;
        }
    }
    //cerr<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    reshNaEratosten();
    int n,a;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>a;
        redica[i]=max_del[a];
    }
    int l=0,len=0,j=0;
    for(int i=0;i<n;)
    {
        while(j<n&&!izp[redica[j]])
        {
            izp[redica[j]]=true;
            ++j;
        }
        //cerr<<i<<" "<<j<<endl;
        if(len<j-i)
        {
            len=j-i;
            l=i;
        }
        izp[redica[i]]=false;
        ++i;
    }
    cout<<l+1<<" "<<l+len<<endl;
    return 0;
}
/*
1
5
4 3 3 4 4
*/

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#define endl "\n"
using namespace std;
using LL=long long;
const int A=1e9+2;
vector<int> redica;
int forSearch;
int n,m,e;
bool bl;
int x;
inline bool ok(int i)
{
    return redica[i]>=x;
}

inline int binary_search_mySecond(int x)
{
    int l=0,r=n-1;
    int ans=-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(redica[m]<=x)
        {
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    //ans=(ans==-1||(redica[ans]!=x))?-1:ans;
    //if(ans==-1||(redica[ans]!=x))
    //    cout<<"no"<<endl;
    //else cout<<"yes"<<endl;
    return ans;
    //return ans;
}

inline int binary_search_myFirst(int x)
{
    int l=0,r=n-1;
    signed int ans=-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        if(ok(m))
        {
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    //bl=(ans==-1||(redica[ans]!=x));
    //if(ans==-1||(redica[ans]!=x))
    //    cout<<"no"<<endl;
    //else cout<<"yes"<<endl;

    return ans;
    //return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=0; i<n; ++i)
    {
        cin>>e;
        redica.push_back(e);
    }
    sort(redica.begin(),redica.end());
    for(int i=0; i<m; ++i)
    {
        cin>>x;
        int ans1=binary_search_myFirst(x);
        int ans2=binary_search_mySecond(x);
        int nes2=ans2-ans1+1;
        int nes3=n-(nes2+ans1);
        cerr<<ans1<<" "<<ans2<<endl;
        if(redica[ans1]!=x)
        {
            ans1=0;
            nes2=0;
        }else if(redica[ans2]!=x)
        {
            ans2=0;
            nes3=0;
        }
        cout<<ans1<<" "<<nes2<<" "<<nes3<<endl;
    }
    return 0;
}
/*
1
5
4 3 3 4 4
*/

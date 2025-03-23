#include<iostream>

using namespace std;
using LL=long long;
using pI=pair<int,int>;
const int N=5e3+1;
pI coords[N];
int n,dy,dx;
LL maxDistance=0,distN=0;
inline LL dist(int i,int j)
{
    dx=abs(coords[i].first-coords[j].first);
    dy=abs(coords[i].second-coords[j].second);
    return dx*dx+dy*dy;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>coords[i].first;
    }
    for(int i=0;i<n;++i)
    {
        cin>>coords[i].second;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            maxDistance=max(maxDistance,dist(i,j));
        }
    }
    cout<<maxDistance<<endl;
}

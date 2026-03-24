#include<iostream>
using namespace std;
const int N=5e5+1;
int aS[N],anS[N];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;++i)cin>>aS[i];
    for(int i=n;i>=1;--i)
    {
        for(int j=i;j<=n;++j)
        {
            if(aS[j]>aS[i])
            {
                anS[i]=max(anS[i],anS[j]+1);
                break;
            }
        }
    }
    for(int i=1;i<=n;++i)
    cout<<anS[i]<<" ";
    cout<<endl;
}
#include <iostream>
using namespace std;
const int K=12;
int redica[K];
int redica2[K];

int f(int n,int k)
{
    if(k<=0)return 0;
    if(n<=0)return 0;
    if(redica[k]<=n)
        return max(f(n,k-1),f(n-redica[k],k-1)+redica2[k]);
    return f(n,k-1);
}

int main()
{
    int n,k;
    cin>>k>>n;
    for(int i=1;i<=k;++i)
    {
        cin>>redica[i]>>redica2[i];
    }
    cout<<f(n,k)<<endl;
}

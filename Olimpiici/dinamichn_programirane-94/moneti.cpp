#include <iostream>
using namespace std;

const int N=100;

int n,sum;
int a[N];
int dp[N][N];
int coin[N][N];

void read() noexcept
{
    cin>>n;
    cin>>sum;
    for(int i=0;i<n;++i)cin>>a[i];
}

int f(int sum,int n) noexcept
{
    if(sum==0)return 0;
    if(sum<0)return 1e9;
    if(n<0)return 1e9;
    if(dp[sum][n]!=0)return dp[sum][n];

    int bez=f(sum,n-1);
    int sys=f(sum-a[n],n)+1;

    if(sys<=bez)
        coin[sum][n]=n;
    else
        coin[sum][n]=coin[sum][n-1];

    return dp[sum][n]=min(bez,sys);
}

int main() noexcept
{
    read();
    cout<<f(sum,n)<<endl;

    while(sum!=0)
    {
        cout<<coin[sum][n]<<endl;
        if(coin[sum][n]==n)n--;
        else sum-=a[n];
    }
}

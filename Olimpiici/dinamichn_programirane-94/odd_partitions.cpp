#include<iostream>
using namespace std;
const int N=2001;
const int M=1e9+7;
int memorization[N][N];
int f(int n,int k)
{
    if(n<0) return 0;
    if(k<0)return 0;
    if(n==0) return 1;
    if(k==0) return 0;
    if (memorization[n][k]) return memorization[n][k];
    return memorization[n][k]=(f(n,k-2)+f(n-k,k))%M;
}
int main()
{
    int n,k;
    cin>>n;
    k=n;
    if (n%2==0)--k;
    cout<<f(n,k)<<endl;
    return 0;
}

#include<iostream>
using namespace std;
const int N=200;
long long memorization[N][N];

long long f(int want_number,int ng)
{
    if(want_number<0)return 0;
    if(want_number==1||want_number==0)return 1;
    if(memorization[want_number][ng])
        return memorization[want_number][ng];

    long long mx=0;
    for(int i=ng; i<=want_number; ++i)
    {
        mx=max(mx,i*f(want_number-i,i+1));
    }
    // cerr<<a<<":"<<mx<<endl;
    return memorization[want_number][ng]=mx;
}
int main()
{
    int n;
    cin>>n;
    cout<<f(n,1)<<endl;
}

#include<iostream>
using namespace std;
const int K=20;
const int N=1e6+2;
const int A=1e6+3;
const int M=1e9+7;
int money[K];
int memorization[N];
int k;
int f(int n)
{
    if(n<0)return 0;
    if(n==0)return 1;
    if (memorization[n])return memorization[n];
    long long ways=0;
    for(int i=0; i<k; ++i)
    {
        ways+=f(n-money[i]);
    }
    //cerr<<n<<":"<<ways<<endl;
    return memorization[n]=ways%M;
}
int main()
{
    int n;
    cin>>n>>k;
    for(int i=0; i<k; ++i)
    {
        cin>>money[i];
    }
    cout<<f(n)<<endl;
    return 0;
}

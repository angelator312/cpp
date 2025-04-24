#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n,br=0;
    cin>>n;
    unsigned long long i = 2;
    for (; i*i < n; i++)
    {
        if(n%i==0)br+=2;
    }
    if(i*i==n)br++;
    if(n==1)cout<<1<<endl;
    else if(n==2)cout<<2<<endl;
    else cout<<br+2<<endl; // 1 i samoto chislo
    return 0;
    
}
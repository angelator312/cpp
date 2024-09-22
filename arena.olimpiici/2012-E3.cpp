#include<iostream>
using namespace std;
using LL=long long;
int main()
{
    long long m,n;
    cin>>m>>n;
    if (m%2)m++;
    if(n%2)n--;
    
    cout<<(m+n)/2<<endl;

}
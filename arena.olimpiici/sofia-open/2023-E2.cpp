#include<iostream>
using namespace std;
int main()
{
    long long n,ns,nd,ne,sum=0;
    cin>>n;
    ns=n/100;
    nd=(n/10)%10;
    ne=n%10;
    sum+=n;
    sum+=ns*100+ne*10+nd;
    sum+=nd*100+ns*10+ne;
    sum+=nd*100+ne*10+ns;
    sum+=ne*100+nd*10+ns;
    sum+=ne*100+ns*10+nd;
    cout<<sum<<endl;

}
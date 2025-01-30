#include<iostream>
#include<set>
#include<cmath>
using namespace std;
using LL =long long;
set<int> setOtInt;
LL NOD(LL a,LL b)
{
    if(a<b)swap(a,b);
    if(b==0)return a;
    return NOD(b,a%b);
}
LL NOK(LL a,LL b)
{
    if(a<b)swap(a,b);
    return a/NOD(b,a)*b;
}
int main()
{
    int l,g,br=0;
    cin>>l;
    for(int i=sqrt(l);i>=0;i--)
    {
        if(l%i==0)
        {
            int b=l/i;
            if(NOD(i,b)==1)

            {
                cout<<i+b<<endl;
                return 0;
            }
        }
    }
    cout<<0<<endl;
    return 0;
}

/*
*/

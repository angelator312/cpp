#include<iostream>
#include<set>
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
    cin>>g>>l;
    for(int i=1;i<=l;i++)
    {
        if(l%i==0)
        {
            if(setOtInt.count(i))break;
            int b=(l*g)/i;
            setOtInt.insert(b);
            setOtInt.insert(i);
            if(NOD(i,b)==g&&NOK(i,b)==l)
                br++;
        }
    }
    cout<<br<<endl;
}

/*
*/

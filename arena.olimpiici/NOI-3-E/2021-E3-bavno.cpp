#include<bits/stdc++.h>
using namespace std;
using LL=long long;

int main()
{
    LL n,br=0,e;
    cin>>n;
    multiset<LL> a;
    // cin>>e;
    // a.insert(e);
    // cin>>e;
    // a.insert(e);
    for(LL i=0; i<n; i++)
    {
        cin>>e;
        a.insert(e);
        if(a.count(e*2)>0 && a.count(e)>=2)
        {
            // a.erase(it);
            a.erase(a.find(e));
            a.erase(a.find(e));
            a.erase(a.find(e*2));
            br++;
        }
        if(a.count(e/2)>=2  && e%2==0)
        {
            //cout<<e<<" "<<a.count(e);
            //cout<<" "<<a.count(e/2);
            //cout<<" "<<a.count(e*2)<<endl;
            a.erase(a.find(e/2));
            a.erase(a.find(e/2));
            a.erase(a.find(e));
            br++;
        }
    }
    cout<<br<<" "<<a.size()<<endl;
    if(a.size()>0)cout<<*a.begin()<<" "<<*(--a.end())<<endl;
    else cout<<"NONE\n";

}
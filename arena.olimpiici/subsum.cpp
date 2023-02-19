#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,w,sum=0,ll=0,sl=0,s=0,length=10000;
    cin >> n >> w;
    int line[n];
    for(int i=0;i<n;i++)
        cin>>line[i];
    sl=s;
    while(s<n)
    {
        while(sl<n)
        {
            ll++;
            sum+=line[sl];
            ///cout<<"w2 s="<<s<<" sl="<<sl<<" sum="<<sum<<" ll="<<ll<<endl;
            if(sum>w)
            {
                break;
            }
            sl++;
        }
        //cout<<"w1 sum="<<sum<<" ll="<<ll<<endl;
        if(sum<w)ll=100000;
        sum=0;
        if(ll<length)length=ll;
        ll=0;
        s++;
    }
    cout<<length<<endl;
    return 0;
}

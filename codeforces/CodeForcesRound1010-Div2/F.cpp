#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define endl "\n"
using namespace std;
using LL=long long;
using pI=pair<int,int>;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    for(int k=0; k<t; ++k)
    {
        int n,pr=0,ptr_a=0;
        cin >> n;
        int ptr_b=n-1;
        int redica[n+1],mnW=0;
        for(int i=0; i<n; ++i)
        {
            cin>>redica[i];
        }
        sort(redica,redica+n);
        cerr<<"sort\n";
        int last=-1;
        /*
        for(int i=0; i<n; ++i)
        {
            if(last!=redica[i])

                last=redica[i];
            else
                redica[i]=0;

        }
        //*/
        for(int i=0; i<n; ++i)
        {
            int mn=1e8,stInd=i;
            if(redica[i]==0)continue;
            for(int j=i+1; j<n; ++j)
            {
                if(redica[j]>0)
                {
                    cerr<<i<<" "<<j<<endl;
                    if(mn>redica[j]%redica[i])
                    {
                        mn=(redica[j]%redica[i]);
                        stInd=j;
                    }
                }
            }
            if(mn<1e8)
            {
                cerr<<mn<<endl;
                mnW+=mn;
                cerr<<i<<","<<stInd<<endl;
                redica[stInd]=0;
            }
        }
        cout<<mnW<<endl;
    }
    return 0;
}
/*
1
5
4 3 3 4 4
*/

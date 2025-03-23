#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using LL = long long;
//-----------------------------------------------------
const int M = 2e5 + 1;
const int A = 1e9 + 5;
const int SBOR = 2 *A;
int zhilt[M];
bitset<A> things(0);
bitset<A> things2(0);
set<int> sborove;
set<int> ms;
int nai_malikZbor = SBOR;
inline int min(int a, int b)
{
    return a < b ? a : b;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> zhilt[i];
        for (int j = 0; j < i; ++j)
        {
            sborove.insert(zhilt[i] + zhilt[j]);
        }
    }
    int sbor = 0,n2=0;
    for (int i = 0; i < m; ++i)
    {
        int e;
        cin >> e;
        // for (int j = 0; j < n2; ++j) {
        //   sbor = e + zhilt[j];
        //   nai_malikZbor = sborove[sbor]?min(nai_malikZbor, sbor):nai_malikZbor;
        // }
        if(things[e])
        {
            things2[e]=1;
        }
        else
        {
            ms.insert(e);
        }
        things[e]=1;
        // zhilt[n2]=e;
        // ++n2;
    }
    int ptr_a=0,msSize,i=0;
    for (int e:sborove)
    {
        auto a=ms.begin();
        //cerr<<e<<" "<<*a<<endl;
        while(a!=ms.end()&&e>*a)
        {
            if(things[e-*a])
                if(e!=2*(*a))
                {
                    nai_malikZbor=min(nai_malikZbor,e);
                    break;
                }
                else
                {
                    if(things2[*a])
                    {
                        nai_malikZbor=min(nai_malikZbor,e);
                        break;
                    }
                }
            ++a;
        }
        if(a==ms.end())break;
        ++i;
    }


    if (nai_malikZbor<SBOR)
    {
        cout << nai_malikZbor << '\n';
        return 0;
    }
    cout << "no volleyball today" << endl;
    return 0;
}

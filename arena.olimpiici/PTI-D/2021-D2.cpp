#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
#define F first
#define S second
using namespace std;
using LL = long long;
using pI = pair<int,int>;
//-----------------------------------------------------
const int N = 1e5 + 1;
const int M = 1e9 + 5;
const int A = 1e9 + 5;
pI redica[N];
int nai_malik = A;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        cin>>redica[i].F>>redica[i].S;
        nai_malik=min(nai_malik,redica[i].S);
    }
    int ob=nai_malik;
    for(int i=0;i<n;++i)
    {
        ob+=max(redica[i].S-nai_malik,0);
    }
    cout<<ob << endl;
    return 0;
}

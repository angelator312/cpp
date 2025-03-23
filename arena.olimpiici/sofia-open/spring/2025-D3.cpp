#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define endl "\n"
using namespace std;
const int MAX_CIFRI=43210;//43205
vector<int> cifri;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k,s,sz=1,j=0;
    cin>>n>>k>>s;
    for(int i=1;i<n;++i)
    {
        sz+=(i==10);
        sz+=(i==100);
        sz+=(i==1000);
        sz+=(i==10000);
        j+=sz;


    }

    int br=0;
    cout<<br<<endl;
    return 0;
}
/*
1
5
4 3 3 4 4
*/

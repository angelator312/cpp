#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
using pr=pair<int,int>;
using pr2=pair<int,pr>;
const int N=1e3+1;
int mas[N];
vector<pr2> a;
int main()
{
    int n,k;
    cin >> n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>mas[i];
        int e=mas[i];
        for(int j=0;j<i;j++)
        {
            int e2=e;
            int e3=mas[j];
            if(e2<e3)swap(e2,e3);
            a.push_back(make_pair(e2-e3,make_pair(e3,e2)));
        }
    }
    sort(a.begin(),a.end());
    /*
    for(auto e:a)
    {
        cout<<e.F<<" "<<e.S.F<<" "<<e.S.S<<endl;
    }
    //*/
    auto e=a[k-1];
    cout<<e.S.F<<" "<<e.S.S<<endl;

}

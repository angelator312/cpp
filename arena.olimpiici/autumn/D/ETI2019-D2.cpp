#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
using LL = long long;
const int N = 2e7 + 1;

//-----------------------------------------------------
bool poGoliamoB(string a,string b)
{
    int n=a.size();
    int m=b.size();
    if(n!=m)
        return n<m;

    for(int i=0; i<n; i++)
    {
        //cout<<a[i]<<" "<<b[i]<<endl;
        if(a[i]-'0'<b[i]-'0')
            return 1;
        if(a[i]-'0'>b[i]-'0')
            return 0;
    }
    return 0;
}
//-----------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    string sMax2,sMax;
    cin>>sMax2;
    sMax=sMax2;
    for(int i=1; i<n; i++)
    {
        string sE;
        cin>>sE;
        //cout<<sE<<" "<<sMax2<<endl;
        if(poGoliamoB(sMax,sE)) //sE>sMax
        {
            sMax2=sMax;
            sMax=sE;
        }
        else if(poGoliamoB(sMax2,sE))   //sE>sMax2
        {
            //cout<<sE<<endl;
            sMax2=sE;
        }
    }

    cout << sMax2 << endl;
}

/*
    ?00+52??=53??
*/

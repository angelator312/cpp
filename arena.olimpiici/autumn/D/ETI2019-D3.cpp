#include <bits/stdc++.h>
using namespace std;
using pr = pair<int, int>;
using LL = long long;
const int N = 1e7 + 1;
multiset<int>imaAvtobusi;
//-----------------------------------------------------

//-----------------------------------------------------

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b, c, t, d,br=0;
    cin >> a>>b>>c>>t>>d;
    for(int i=0; ; i++)
    {
        int e=i*a;
        int e2=i*b;
        int e3=i*c;
        imaAvtobusi.insert(e);
        imaAvtobusi.insert(e2);
        imaAvtobusi.insert(e3);
        if(e>=t*d&&e2>=t*d&&e3>=t*d)
            break;
    }
    /*
    for(auto a:imaAvtobusi)
        cout<<a<<" ";
    cout<<endl;
    //*/
    for(int i=t*(d-1); i<t*d; i++)
    {
        br+=imaAvtobusi.count(i)==3;
    }
    cout << br<< endl;
}

/*
    1 2 1 3 1
*/

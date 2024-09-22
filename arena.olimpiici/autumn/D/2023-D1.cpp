#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    set<int> heights;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        heights.insert(e);
    }

    int last = 100000000, localLen = 0;
    int mLen = 0;

    for (int i : heights)
    {
        if (last + k >= i)
        {
            // cout<<i<<endl;
            localLen++;
        }
        else
        {
            // cout<<"len:"<<localLen<<endl;
            // cout<<i<<endl;
            mLen = max(mLen, localLen);
            localLen = 1;
        }
        last = i;
    }
    mLen = max(mLen, localLen);

    cout << mLen << endl;
    return 0;
}
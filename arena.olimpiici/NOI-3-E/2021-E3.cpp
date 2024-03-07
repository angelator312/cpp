#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAX = 1e5 + 2;
struct SpecStr
{
    int a[MAX]{};
    int size = 0;
    vector<int> b;
    void insert(int koe)
    {
        a[koe - 1]++;
        size++;
        if (a[koe - 1] == 1)
        {
            // cout << "size++" << endl;
            b.push_back(koe);
        }
    };

    inline int find(int koe) { return koe - 1; };

    inline int count(int koe)
    {
        if (koe - 1 < 0)
        {
            return 0;
        }
        // cout << "count" << endl;
        return a[koe - 1];
    };

    void erase(int koe)
    {
        if (koe >= 0)
        {
            a[koe]--;
            size--;
        }
    }
    inline void sortV()
    {
        sort(b.begin(), b.end());
    }
    int minValue()
    {

        for (int i = 0; i < b.size(); i++)
        {
            if (a[b[i] - 1] > 0)
                return b[i];
        }
        return 0;
    }
    int maxValue()
    {

        for (int i = b.size() - 1; i > 0; i--)
        {
            if (a[b[i] - 1] > 0)
                return b[i];
        }
        return 0;
    }
};
int main()
{
    LL n, br = 0, e;
    cin >> n;
    SpecStr a;
    // cin>>e;
    // a.insert(e);
    // cin>>e;
    // a.insert(e);
    for (LL i = 0; i < n; i++)
    {
        cin >> e;
        a.insert(e);
        if (a.count(e * 2) > 0 && a.count(e) >= 2)
        {
            // a.erase(it);
            a.erase(a.find(e));
            a.erase(a.find(e));
            a.erase(a.find(e * 2));
            br++;
        }
        if (e % 2 == 0 && a.count(e / 2) >= 2)
        {
            // cout<<e<<" "<<a.count(e);
            // cout<<" "<<a.count(e/2);
            // cout<<" "<<a.count(e*2)<<endl;
            a.erase(a.find(e / 2));
            a.erase(a.find(e / 2));
            a.erase(a.find(e));
            br++;
        }
    }
    cout << br << " " << a.size << endl;
    a.sortV();
    if (a.size > 0)
        cout << a.minValue() << " " << a.maxValue() << endl;
    else
        cout << "NONE\n";
}
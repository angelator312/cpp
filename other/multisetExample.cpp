#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> a;
    multiset<int, greater<int>> a2;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        a.insert(e);
        a2.insert(e);
    }

    for (auto i : a)
    {
        cout << i << " ";
        cout << a.count(i) << endl;
    }
    

    for (auto i = a2.begin(); i != a2.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    return 0;
}

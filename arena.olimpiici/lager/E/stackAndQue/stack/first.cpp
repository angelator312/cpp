#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> a;
    stack<int> b;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        a.push(e);
    }
    while (!a.empty())
    {
        b.push(a.top());
        a.pop();
    }

    while (!b.empty())
    {

        cout << b.top();
        b.pop();
    }

    cout << endl;
}
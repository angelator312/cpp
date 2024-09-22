#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    std::queue<string> a;
    std::queue<string> b;
    std::queue<string> c;
    for (int i = 0; i < n; i++)
    {
        string e;
        cin >> e;
        if (e[0]=='m')
            a.push(e);
        else if (e[0]=='k')
            b.push(e);
        else
            c.push(e);
    }

    while (!a.empty())< 51
    {
        cout << a.front()<<" ";
        a.pop();
    }
    while (!b.empty())
    {
        cout << b.front()<<" ";
        b.pop();
    }
    while (!c.empty())
    {
        cout << c.front()<<" ";
        c.pop();
    }
    cout << endl;
}
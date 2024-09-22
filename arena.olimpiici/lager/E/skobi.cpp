#include <bits/stdc++.h>
using namespace std;

bool isOpenSk(char a)
{
    string c = "([{";
    for (char b : c)
    {
        if (b == a)
            return true;
    }
    return false;
}

bool areOposite(char a, char b)
{
    string op = "([{";
    string cl = ")]}";
    for (int i = 0; i < 3; i++)
    {
        if(a==op[i] && b==cl[i])return true;
    }
    

    return false;
}

bool isOk(string s)
{
    stack<char> a;
    int Len=0;
    char b;
    while(b!='\n')
    {
        if(isspace(b))continue;
        if (isOpenSk(b))
        {
            a.push(b);
            Len++;
        }
        else
        {
            // cout << a.top() << " " << b << endl;
            if (Len&&areOposite(a.top(), b))
            {
                a.pop();
                Len--;
            }
            else
                return false;
        }
    }
    return !Len;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        // getline(cin, s);
        cin>>s;
        if (isOk(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
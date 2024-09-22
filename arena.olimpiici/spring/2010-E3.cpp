#include <bits/stdc++.h>
using namespace std;
using LL = long long;
// const int N = 9;

// int a[N];

int main()
{
    char c, a;
    cin >> c;
    bool chisl = false; // chisla
    bool bukvi = 1;     // bukvi
    int chis = 0, buk = 0;
    int chisL = 0, bukL = 0;
    vector<char> ch, chP;
    vector<char> bukv, bukvP;

    for (cin >> a; a != c; cin >> a)
    {
        if ('0' <= a && a <= '9')
        {
            if (chisl)
            {
                chisL++;
                ch.push_back(a);
            }
            else
            {
                if (bukL > buk)
                {
                    buk = bukL;
                    bukvP = bukv;
                    bukL = 0;
                }
                bukv = {};

                chisL = 1;
                bukvi = 0;
                chisl = 1;
                ch.push_back(a);
            }
        }
        else if ('a' <= a && a <= 'z')
        {
            if (bukvi)
            {
                bukL++;
                bukv.push_back(a);
            }
            else
            {
                if (chisL > chis)
                {
                    chis = chisL;
                    chP = ch;
                    chisL = 0;
                }
                ch = {};

                bukL = 1;
                chisl = 0;
                bukvi = 1;
                bukv.push_back(a);
            }
        }
        else
        {
            if (chisL > chis)
            {
                chis = chisL;
                chP = ch;
                chisL = 0;
            }
            ch = {};
            if (bukL > buk)
            {
                buk = bukL;
                bukvP = bukv;
                bukL = 0;
            }
            bukv = {};
            chisl = 0;
            bukvi = 0;
        }
    }
    if (chisL > chis)
    {
        chis = chisL;
        chP = ch;
    }
    if (bukL > buk)
    {
        buk = bukL;
        bukvP = bukv;
    }
    // cout << chis << endl;
    for (auto x : chP)
    {
        cout << x;
    }
    if (!chP.empty())
        cout << endl;
    for (auto x : bukvP)
    {
        cout << x;
    }
    if (!bukvP.empty())
        cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int i = 0, g = 1, gM = -1;
    char c = 'a' - 1;
    while (n > i)
    {
        while (s[i + 1] == s[i])
        {
            i++;
            g++;
        }
        // cout << g << endl;
        if (g == gM && s[i] > c)
            c = s[i];
        if (g > gM)
        {
            c = s[i];
            gM = g;
            // g = 1;
        }
        g=1;
        i++;
    }
    if (g == gM && s[i] > c)
        c = s[i];
    if (g > gM)
    {
        c = s[i];
        gM = g;
        // g = 0;
    }
    cout << gM << " " << c << endl;
}
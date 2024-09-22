#include <bits/stdc++.h>
using namespace std;
bool isOpenSk(char a)
{
    string c = "([{";
    int o = 0;
    for (char b : c)
    {
        if (b == a)
            return o;
        o++;
    }
    return 3;
}
bool isCloseSk(char a)
{
    string c = ")]}";
    for (char b : c)
    {
        if (b == a)
            return true;
    }
    return false;
}

bool isOk(string s)
{

    int osk[3];
    int zsk[3];
    int Len;
    for (char b : s)
    {
        if (isspace(b))
            continue;
        if (isOpenSk(b) < 3)
        {
            cout <<b<<" "<<isOpenSk(b) << " ";
            osk[isOpenSk(b)]++;
            Len++;
        }
        else
        {
            int c = isCloseSk(b);
            if (osk[c] == 0)
                return false;
            else
                osk[c]--, Len--;
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
        cin >> s;
        if (isOk(s))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
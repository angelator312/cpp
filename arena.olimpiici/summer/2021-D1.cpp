#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int H = 1e3;
const int L = 2e3 - 1;

int m[L][H];
int mSr;
int tr(int &zI, int &len, int &zL, int &zH)
{

    // int zH=h;
    for (int i = zL; i < zL + len; i++)
    {
        cout << "[ " << i << " ] [ " << zH << " ] :" << zI << endl;
        m[i][zH] = zI;
        zI++;
    }
    len -= 2;
    zH--;
    int kr = 0;
    for (; zH > 0; len--)
    {
        cout << "[ " << zL + len << " ] [ " << zH << " ] :" << zI << endl;
        m[zL + len][zH] = zI;
        kr = zL + len;
        zI++;
        zH--;
    }
    if (zL + len == mSr)
    {
        m[zL + len][zH] = zI;
        kr = zL + len;
        zI++;
        // zH--;
        // cout << zH << endl;
    }
    zH++;
    if (len > 1)
    {
        zH++;
        len--;
    }

    cout << len << endl;
    for (; len >= 1; len--) // pod vypros "len >= 1"
    {
        cout << "[ " << zL + len << " ] [ " << zH << " ] :" << zI << endl;
        m[zL + len][zH] = zI;
        kr = zL + len;
        zI++;
        zH++;
    }
    len++;
    zH--;
    return kr;
}

// len-=3 za         cout<<"[ "<<zL+len<< " ] [ "<<zH<< " ] :"<<zI<<endl;
// red
int main()
{
    int n, h;
    cin >> n;
    mSr = (n * 2 - 1) / 2;
    int zH = n - 1, zI = 1, len, zL = 0;
    for (int i = n * 2 - 1; i > 1; i -= 4)
    {
        len = i;
        zL = tr(zI, len, zL, zH) + 1;
        // zL += len;
        cout << zL << " " << i << endl;
    }

    // tr(zI, len, zL, zH);
    // cout << zI << " " << len << " " << zL << " " << zH << "\n";

    int biggestL = n * 2 - 1;
    h = 0;
    for (int i = 1; i <= biggestL; i += 2)
    {
        int a = n - h;
        a--;
        // cout<<a<<endl;
        for (int j = a; j < a + i; j++)
        {
            cout << m[j][h] << " ";
        }
        h++;
        cout << endl;
    }

    return 0;
}
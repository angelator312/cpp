#include <iostream>
using namespace std;
int main()
{
    int ca, cb, cc,Ol2[10]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, Ol3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            loc = 0, ioc = 0;
    string a,b,c;
    cin >> ca >> a >> cb >> b >> cc >> c;
    int Ol[10]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},O[10]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < ca; i++)
    {
        int e=a[i]-'0';
        Ol[e]++;
    }
    for (int i = 0; i < cb; i++)
    {
        Ol2[b[i] - '0']++;
    }
    for (int i = 0; i < cc; i++)
    {
        Ol3[c[i] - '0']++;
    }
    for (int i = 0; i <= 9; i++)
    {
        if (Ol[i] >=1 && Ol2[i] >=1 && Ol3[i] >=1)
        {
            O[i] = 1;
            ioc++;
        }
    }
    cout << ioc << endl;
    if (ioc == 0)
        return 0;
    else
        for (int i = 0; i <= 9; i++)
        {
            if (O[i] == 0)
                continue;
            loc++;
            if (loc == ioc)
                cout << i << endl;
            else
                cout << i << " ";
        }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using LL = long long;
// inline char itoc(int a){return (char)(a+'0');}
// inline int ctoi(char a){return (a-'0');}
// bool startEq(char a,int b){return a==(char)(b+'a')||a==(char)(b+'A');}
int main()
{
    int n, br = 999;
    cin >> n;
    int k = n / 6, p = n / 8;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < p; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (i * 6 + j * 8 == n && i + j < br)
            {
                br = i + j;
            }
        }
    }

    if (br == 999)
    {
        cout << "No solution" << endl;
    }
    else
        cout << br << endl;

    return 0;
}
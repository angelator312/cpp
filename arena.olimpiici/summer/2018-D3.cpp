#include <iostream>

using namespace std;
using LL = long long;

int main()
{
    string a;
    cin >> a;
    int n = a.size();
    int b[n + 1][26]{};
    LL br = 0;
    b[0][a[0] - 'a']++;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 26; j++)
            b[i][j] = b[i - 1][j];

        b[i][a[i] - 'a']++;
        // cout << b[i][a[i]-''] << endl;;
    }

    for (int i = 1; i < n; i++)
    {
        LL brL = 0;
        LL brL2 = 0;
        int c = a[i] - 'a';
        for (int j = 0; j < c; j++)
            brL += b[i][j];
        for (int j = c + 1; j < 26; j++)
            brL2 += b[n - 1][j] - b[i - 1][j];
        br += brL * brL2;
    }

    cout << br << endl;
    return 0;
}
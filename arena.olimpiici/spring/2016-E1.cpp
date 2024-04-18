#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using dAP = pair<int, int>;
const int N = 3e3;
bool tuhl[N + 1];
LL izpolzvaniTuhlichki[N + 1]{};
int delAndPow(int a)
{
    int aM = a;
    for (int i = 1; i <= a; i++)
        if (a % i == 0 && tuhl[i])
            return i;
    return 0;
}

LL broiNaTuhli(int chis)
{
    return pow(chis, 3);
}

int main()
{
    int n, m, neIzpolzvTuhli = 0; // broi
    LL izpolzvTuhliBr = 0;
    cin >> n;
    vector<int> tuhli;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        tuhl[a] = 1;
        tuhli.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        int b = delAndPow(a);
        if (b == 0)
            neIzpolzvTuhli++;
        else
        {
            LL c = broiNaTuhli(a / b);
            // cout << b << " " << c << endl;
            izpolzvTuhliBr += c;
            izpolzvaniTuhlichki[b] += c;
        }
    }
    cout << izpolzvTuhliBr << " " << neIzpolzvTuhli << endl;

    for (auto i : tuhli)
        cout << izpolzvaniTuhlichki[i] << " ";
    cout << endl;
}
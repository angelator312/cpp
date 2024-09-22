#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6 + 5;

LL factorieli[N];
int reshenia[N];
int resheto[N];

LL factoriel(int a)
{
    if (factorieli[a])
        return factorieli[a];
    else
    {
        LL b = a * factoriel(a - 1);
        factorieli[a] = b;
        return b;
    }
}

int stepeni(LL a)
{
    // return resheto[a];
    int br = 0;
    while (a % 2 == 0)
    {
        br++;
        a /= 2;
    }

    for (int i = 3; i * i < a; i += 2)
    {
        while (a % i == 0)
        {
            br++;
            a /= i;
        }
    }
    return br + 1;
}

void reshetoNaEratosten()
{
    for (int j = 2 * 2; j < N; j += 2)
    {
        int d = j;
        while (d % 2 == 0)
        {
            resheto[j]++;
            // cout << resheto[j] << endl;
            d /= 2;
        }
    }
    for (int i = 3; i < N; i += 2)
    {
        if (resheto[i])
            continue;
        for (int j = i * 2; j < N; j += i)
        {
            int d = j;
            while (d % i == 0)
            {
                resheto[j]++;
                // cout << resheto[j] << endl;
                d /= i;
            }
        }
    }
}

int main()
{
    factorieli[0] = 1;
    int n;
    cin >> n;
    // reshetoNaEratosten();
    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        if (reshenia[e])
        {
            cout << reshenia[e] << " ";
            continue;
        }
        int a = stepeni(factoriel(e));
        reshenia[e] = a;
        cout << a << " ";
    }

    cout << endl;
}
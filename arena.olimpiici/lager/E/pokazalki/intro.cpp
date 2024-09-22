#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
int prefix[N];

int main()
{
    int n, k;
    cin >> n >> k;
    cin >> prefix[0];
    for (int i = 1; i < n; i++)
    {
        int e;
        cin >> e;
        prefix[i] = prefix[i - 1] + e;
    }
    prefix[n] = 0;
    int b = 1; // b-krai
    while (prefix[b] < k)
    {
        b++;
    }
    int bigLen = b;
    // cout << b << endl;
    for (int i = 3; i < n; i++) // i- nachalo
    {
        while (prefix[b] - prefix[i - 1] < k && b < n)
        {
            b++;
            cout << i << " " << b << endl;
        }
        // if (b == n && prefix[b] - prefix[i - 1] < k)
        //     bigLen = max(bigLen, (b - i) + 1);
        // else
            bigLen = max(bigLen, b - i);
    }
    cout << bigLen << endl;
}
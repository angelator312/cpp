#include <bits/stdc++.h>
using namespace std;

// (n+1)×(n÷2)+p=S
// n*(n/2) + (n/2) = S-p
// (n/2)(n+1) = S-p

int main()
{
    long long s;
    cin >> s;
    long long sum = 1;
    int n = 1;
    int lastN = 1;
    while (sum < s)
        n++, lastN++, sum += lastN;

    sum-=lastN;
    lastN--;
    n--;
    int p = s - sum;
    if (p > lastN || p==0)
        cout << 0 << endl;
    else
        cout << n << " " << p << endl;

    return 0;
}
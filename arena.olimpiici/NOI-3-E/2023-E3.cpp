#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX_N = 4e4 + 4;
long long ans = 0;
long long k;
int n;
int dels[MAX_N];
void solve(int x)
{
    for (int y = 1; y * y <= x; y++)
    {
        if (x % y)
            continue;
        dels[x]++;
        int ny = x / y;
        if (ny != y)
            dels[x]++;
    }
    long long l = k * 1LL * dels[x];
    if (l < x)
        return;
    long long koe = k * 1LL * dels[x] / __gcd(k * 1LL * dels[x], 1LL * x);
    for (int y = koe; y <= x; y += koe)
    {
        long long l = k * 1LL * dels[x] * 1LL * dels[y];
        long long r = 1LL * x * 1LL * y;
        if (l == r)
            ans++;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        solve(i);
    }
    cout << ans << "\n";
    return 0;
}
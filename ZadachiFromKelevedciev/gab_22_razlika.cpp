#include <bits/stdc++.h>
#include <cmath>
using namespace std;
// const int N;
pair<long long, long long> del(long long N)
{
    long long o[3] = {1, N, N - 1};
    for (int i = 2; i < sqrt(N); i++)
    {
        if (o[2] == 0)
        {
            pair<long long, long long> out;
            out.first = o[0];
            out.second = o[1];
            return out;
        }

        if (N % i == 0)
        {
            int e2 = N / i, mx = max(e2, i), mn = min(e2, i), razl = mx - mn ;
            if (razl < o[2])
            {
                o[2] = razl;
                o[1] = mx;
                o[0] = mn;
            }
        }
    }
    pair<long long, long long> out;
    out.first = o[0];
    out.second = o[1];
    return out;
}
int main()
{
    long long N;
    cin >> N;
    pair<long long, long long> o = del(N);
    cout << o.first << " " << o.second << endl;
}

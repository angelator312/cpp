#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int delsBr(int n)
{
    int br = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (n / i != i)
                br += 2;
            else
                br++;
        }
        // cout<<br<<" s"<<i<<endl;
    }

    return br;
}

void dels(LL n, vector<int> &a)
{

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;
        a.push_back(i);
        if (n / i != i)
            a.push_back(n / i);
    }
    // return a;
}
void loadDelitels(long long &n, vector<int> &a, set<int> &b, vector<int> &c)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;
        if (n / i != i)
        {
            c.push_back(i);
            c.push_back(n / i);
            for (int j : a)
            {
                // cout << j*i << endl;
                b.insert(j * i);
                b.insert((n / i) * j);
            }
        }
        else
        {
            c.push_back(i);

            for (int j : a)
            {
                b.insert(j * i);
                // cout << 0 << endl;
            }
        }
    }
}
int main()
{
    long long A, B;
    cin >> A >> B;
    vector<int> a;
    dels(A, a);
    set<int> b;
    vector<int> c; // del B
    loadDelitels(B, a, b, c);
    int dAB = b.size();
    // cout << dAB << endl;
    int br=0;
    for (int x : a)
    {

        int dX = delsBr( x);
        // cout<<x<<" "<<dX<<endl;

        for (auto y : c)
        {
            int dY = delsBr(y);
            if (dAB % (dY + dX) == 0)
            {
                // cout << dY << endl;
                // cout << (dY + dX) << endl;
                // cout << x << " " << y << "\n";
                br++;
            }
        }
    }
    cout<<br<<endl;
}
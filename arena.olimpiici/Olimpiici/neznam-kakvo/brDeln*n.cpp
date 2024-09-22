#include <bits/stdc++.h>
using namespace std;
using LL = long long;

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
void loadDelitels(long long &n,vector<int> a,set<int> &b)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i != 0)
            continue;
        if (n / i != i)
            for (int j : a)
            {
                // cout << j*i << endl;
                b.insert(j * i);
                b.insert((n / i) * j);
            }
        else
            for (int j : a)
            {
                b.insert(j * i);
                // cout << 0 << endl;
            }
    }
    
}
int main()
{
    long long n;
    cin >> n;
    vector<int> a;
    dels(n,a);
    set<int> b;
    loadDelitels(n,a,b);
    cout<<b.size()<<endl;
}
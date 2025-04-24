#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 1;
// 16 -first 5 div
int sum = 0;
int reshetoNaErat[N];

void resheto(int n)
{
    for (int i = 2; i*2 <= n; i++)
    {
        
        for (int j = 2 * i; j <= n; j += i)
            reshetoNaErat[j]++;
    }
}

int main()
{
    int n;
    cin >> n;
    resheto(n);
    for (int i = 4; i*i <=n; i++)
    {
        if (reshetoNaErat[i*i] == 3) // izpuskame sobstvenoto
        {
            // cout<<i<<endl;
            sum += i*i;
        }
    }
    
    cout << sum << endl;
}
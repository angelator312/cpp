#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (k == 0)
    {
        while (n % 2) // n%2 ==1
        {
            n = (n + 1) / 2;
        }
        cout << n << endl;
    }
    else if (k == 1)
    {
        while (!(n %2==0&&n%4>0)) // n%2 ==1
        {
            n = (n * 2) / 3;
            cout << n << endl;
        }
        //    cout << mLen << endl;
    }
    return 0;
}
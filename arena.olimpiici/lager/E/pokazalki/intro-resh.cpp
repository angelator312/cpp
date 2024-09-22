#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int bigLen = 0;
    int sum = 0;
    int j = -1;
    // cout << b << endl;

    for (int i = 0; i < n; i++) // i- nachalo
    {
        //разширяваме надясно
        //опитваме да вземем j+1
        while (j + 1 < n && sum + a[j + 1] <= k)
        {
            sum += a[j + 1];
            j++;
        }
        
        bigLen = max(bigLen,( j - i)+1);
        // От сумата маахме първия елемент
        sum -= a[i];
        cout<<i<<" "<<j<<endl;
    }
    cout << bigLen << endl;
}
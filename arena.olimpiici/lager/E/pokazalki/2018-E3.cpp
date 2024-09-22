#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int chis[N];

bool isOk(int x,int raz)
{
    
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int bigLen = 0;
    int raz = 0;
    int j = -1;
    // cout << b << endl;

    for (int i = 0; i < n; i++) // i- nachalo
    {
        // разширяваме надясно
        // опитваме да вземем j+1
        while (j + 1 < n && chis[a[j + 1]] <= 1 &&raz)
        {
            if (chis[a[j + 1]] == 0)
                raz++;
            j++, chis[a[j]]++;
        }
        bigLen = max(bigLen, (j - i) + 1);
        // От сумата махме първия елемент
        chis[a[i]]--;
        if (chis[a[i]] == 0)
            raz--;
        cout << i + 1 << " " << j + 1<<" : "<<raz << endl;
    }
    cout << bigLen << endl;
}
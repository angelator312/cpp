#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int chis[N];
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

    int b,c;
    // cout << b << endl;

    for (int i = 0; i < n; i++) // i- nachalo
    {
        // разширяваме надясно
        // опитваме да вземем j+1
        while (j + 1 < n )
        {
            if (chis[a[j + 1]] == 0)
                raz++;
            if (raz > 2)
            {
                raz--;
                break;
            }
            j++, chis[a[j]]++;
        }
        if (bigLen < (j - i) + 1)
        {
            bigLen =(j - i) + 1;
            b=i;
            c=j;
        }
        // От сумата махме първия елемент
        chis[a[i]]--;
        if (chis[a[i]] == 0)
            raz--;
        // cout << i + 1 << " " << j + 1 << " : " << raz << endl;
    }
    cout << b+1<<" "<<bigLen << endl;
}
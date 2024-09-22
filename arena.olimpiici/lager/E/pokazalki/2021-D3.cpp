#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
const int K = 1e5;
int chis[N];
vector<int> chisVRedici[N];

int main()
{
    int k,n;
    cin >> n>>k;
    set<int> a[k];
    for (int i = 0; i < k; i++)
    {
        int k;
        cin >>k;
        for (int j = 0; j < k; j++)
        {
            int e;
            cin >> e;
            if (!a[i].count(e))
            {
                chisVRedici[e].push_back(i);
                a[i].insert(e);
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
       for(int b:a[i])
       {
            cout<<b<<" \n";
            for(int c: chisVRedici[b])
                cout<<c<<" ";
            cout<<"\n";
       }
    }

    int bigLen = 0;
    int raz = 0;
    int j = -1;
    // // cout << b << endl;

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
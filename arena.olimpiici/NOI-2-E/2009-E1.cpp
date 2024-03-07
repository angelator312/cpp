#include <bits/stdc++.h>
#include <algorithm>
#define MAX_LENGTH 24
using namespace std;
using LL = int;
// inline char itoc(int a){return (char)(a+'0');}
// inline int ctoi(char a){return (a-'0');}
// bool startEq(char a,int b){return a==(char)(b+'a')||a==(char)(b+'A');}
// 28657-23chislo
LL chFib[MAX_LENGTH] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
void popylFib()
{
    for (int i = 9; i < MAX_LENGTH; i++)
    {
        chFib[i] = chFib[i - 2] + chFib[i - 1];
    }
}
LL chIndFib(LL a)
{
    return find(chFib, chFib + MAX_LENGTH, a) - chFib;
}
LL doChislo(LL a)
{
    int i = chIndFib(a);
    if (i == MAX_LENGTH)
    {
        return lower_bound(chFib,chFib+MAX_LENGTH,a)-chFib;
    }
    return i;
}
int main()
{
    popylFib();
    // for (int i : chFib)
    // {
    //     cout << i << " ";
    // }
    // cout<<endl;
    // cout<<doChislo(14)<<endl;
    string a;
    cin >> a;
    // cout << a.size() << endl;
    // cout << chIndFib(a.size())-1 << endl;
    do
    {
        cout<<doChislo(a.size())-1<<endl;
    }
    while(cin>>a);

    return 0;
}
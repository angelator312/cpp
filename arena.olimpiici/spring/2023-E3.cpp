#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;
using LL = long long;
using OtDo = tuple<int, int, int>;
const int L = 1e8 + 1;
int parch[L];

int main()
{
    char a;
    int brParcheta, n;
    int naiGolqmTr = -1, naiMnogoPol = -1;
    int naiGIndex = n + 1, naiMPIndex = n + 1;
    cin >> n >> n;
    OtDo mas[n];
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        OtDo d(i, b, c);
        mas[a] = d;

        int Len2 = (c - b) + 1;

        for (int j = b; j <= c; j++)
            if (parch[j] > a || parch[j] == 0)
                parch[j] = a;

        // cout<<a<<" "<<b<<" "<<c<<endl;
        // cout<<naiGolqmTr<<endl;

        if (naiGolqmTr < Len2)
        {
            naiGolqmTr = Len2;
            naiGIndex = i;
        }
        else if (naiGolqmTr == Len2 && naiGIndex > a)
        {
            // cout<<"2 "<<a<<" "<<Len2<<endl;
            naiGIndex = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int len = 0, a, b, c;
        tie(a, b, c) = mas[i];
        // cout << a << " " << b << " " << c << " " << endl;

        for (int j = b; j <= c; j++)
        {
            // if (b == 7)
                // cout << parch[j] << endl;
            if (parch[j] == i)
                len++;
        }

        if (naiMnogoPol < len)
        {
            //cout << "3 " << i << " " << a << " " << len << endl;
            naiMnogoPol = len;
            naiMPIndex = a;
        }
        else if (naiMnogoPol == len && naiMPIndex > a)
        {
            // cout<<"4 "<<a<<endl;
            naiMPIndex = a;
        }
    }
    cout << naiGIndex + 1 << endl;
    cout << naiMPIndex + 1 << endl;
    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;
using LL = long long;
int main()
{
    float n;
    int m;
    cin >> m >> n;
    float mas[m + 1]{};

    for (int i = 0; i < n; i++)
    {
        int e;
        cin >> e;
        mas[e]++;
    }

    for (int i = 1; i <= m; i++)
        cout << fixed << setprecision(2) << (float)(mas[i] / n) * 100 << "%" << endl;
}
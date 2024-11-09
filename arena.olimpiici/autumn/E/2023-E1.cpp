// TEST_ZIP: w
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int j = 0;
    bool mas[n]{};
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        mas[i] = c == '1';
    }
    cout << mas[3]<<mas[1] << endl;
    for (int i = n - 1; i > 0; i--)
    {
        if (k == 0)
        {
            break;
        }
        if (mas[i])
            continue;
        if (!mas[i])
        {
            while (!mas[j])
                j++;
            mas[i] = 1;
            mas[j] = 0;
            j++;
            k--;
        }
    }
    for (int i = 0; i < n; i++)
        cout << mas[i];
    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int len = n / 2;
    if (n % 2 == 0)
    {
        // poslednoto e A
        for (int i = len - 1; i >= 0; i--)
            cout << (char)('A' + (n - (i + 1))) << (char)('A' + i);
    }
    else
    {
        // poslednoto e 'A'+(n-1)
        // cout << (char)('A' + len);
        // for (int i = 0; i < len; i++)
        //     cout << (char)('A' + i) << (char)('A' + (n - (i + 1)));

        int mas[n]{}, j = 0;
        for (int i = n - 2; i > 0; i -= 2)
        {

            // cout << i << endl;
            mas[i] = j,
            j++;
        }
        for (int i = 0; i < n; i += 2)
            mas[i] = j,
            j++;
        for (int i = 0; i < n; i++)
            cout << (char)(mas[i] + 'A');
    }
    cout << endl;
    return 0;
}
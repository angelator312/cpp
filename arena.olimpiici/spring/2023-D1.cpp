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
    int n;
    cin >> n;
    int mas[n];
    int a, br = 0;
    cin >> a;
    mas[0] = a;
    for (int i = 1; i < n; i++)
    {
        cin >> a;
        mas[i]=a;
        //cout << i << endl;
        for (int j = i - 1; j >= 0; j--)
        {
            int e = mas[j], d = 1;
            do
            {
                //cout << " " << i << " " << j<< " " << d<< " " << a<< " " << e<< endl;
                if ((a / d) % 10 == (e / d) % 10)
                {
                    br++;
                }
                d *= 10;
            } while (e >= d || a >= d);
        }
    }
    cout << br << endl;
    return 0;
}

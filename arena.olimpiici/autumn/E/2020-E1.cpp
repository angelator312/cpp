// TEST_ZIP: https://arena.olimpiici.com/api/public/problems/1338/zip?download=true
#include <iostream>
using namespace std;
int main()
{
    int l, l2, r, r2, k;
    cin >> l >> r >> l2 >> r2 >> k;
    int minR = min(r, r2), maxL = max(l, l2), T = 0;
    if (k > maxL && k < minR)
    {
        if (maxL <= minR)
        {
            T = max((k - maxL), minR - k) + 1;
        }
    }
    else
    {
        if (maxL <= minR)
        {
            T = minR - maxL;
            T++;
        }
        if (k==minR)
        {
            T--;
        }
        
    }

    cout << T << endl;
}
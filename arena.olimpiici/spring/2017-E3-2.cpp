#include <bits/stdc++.h>
using namespace std;
using LL = int;

int main()
{
    int n;
    cin >> n;

    LL mas[n];

    for (LL i = 0; i < n; i++)
        cin >> mas[i];

    LL lengthMain = -1, rightIndex = 0, leftIndex = 0;

    for (LL right = 0; right <= n - 2;)
    {
        // bool b=false;
        LL start = right;
        while (right <= n - 2 && mas[right] - 2 >= mas[right + 1])
            right++;
        
        LL mexdinen = right;
        if (mexdinen == start)
            right++;
        // cout<<mas[right]<<" "<<mas[right+1]<<endl;
        if (mas[right] - 1 == mas[right + 1] &&right <= n - 2 && mas[right] + 2 <= mas[right + 1])
            right++;

        while (right <= n - 2 && mas[right+1] + 2 <= mas[right + 2])
            right++;

        if (mexdinen == right)
            right++;

        if (right >= n)
            right = n - 1;
        

        LL razl = (right - start) - 1;

        if (razl > lengthMain)
        {
            lengthMain = razl;
            rightIndex = start;
            leftIndex = right;
            // cout << lengthMain << " ";
            // cout << rightIndex + 1 << " ";
            // cout << leftIndex + 1 << endl;
        }
        // if(b)break;
    }

    cout << lengthMain << " ";
    cout << rightIndex + 1 << " ";
    cout << leftIndex + 1 << endl;

    return 0;
}
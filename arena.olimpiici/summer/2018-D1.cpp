#include <iostream>
#include <vector>
using namespace std;
using LL = long long;

int main()
{
    vector<int> a;
    string s;
    cin >> s;
    int len = s.size(), k, br = 0;
    cin >> k;

    a.push_back(s[0] == '0');
    if(s[0]=='0' && k==1)br++;
    for (int i = 1; i < len; i++)
    {
        if (s[i] == '0')
        {
            if(k==1)br++;
            a.push_back(a[i-1] + 1);
        }
        else
            a.push_back(a[i-1]);

        // cout <<s[i]<< a[i] << endl;
        for (int j = i - 1; j > 0; j--)
        {
            int mn;
            if (j == 0)
                mn = 0;
            else
                mn = a[j - 1];

            if (a[i] - mn == k)
                br++;
        }
        if (a[i] == k)
            br++;
    }

    cout << br << endl;
    return 0;
}
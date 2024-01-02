#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{
    int ch[2] = {-1, -1}, n, ci = 0;
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        char e;
        cin >> e;
        if (e >= '0' && e <= '9')
        {
            if (ch[ci] > -1)
            {
                ch[ci] *= 10;
                ch[ci] += e - '0';
            }
            else
            {
                ch[ci] = e - '0';
            }
        }
        else
        {
            if (ch[ci] > -1)
                ci++;
        }
    }
    if (ch[0] == -1)
    {
        cout << "N/A" << endl;
        return 0;
    }

    cout << ch[0] * n << endl;
    if (ch[1] > -1)
    {
        cout << ch[1] * n << endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int a[3][3];
inline bool c(int Ia, int Ib)
{
    return (a[Ia][Ib] == 9);
}
int bombs(int aI, int b)
{
    if (a[aI][b] == 9)
        return 9;
    int o = 0;
    switch (aI)
    {
    case 0:
        switch (b)
        {
        case 0:
            if (c(0, 1))
                o++;
            if (c(1, 1))
                o++;
            if (c(1, 0))
                o++;
            break;

        case 1:
            if (c(0, 0))
                o++;
            if (c(1, 1))
                o++;
            if (c(1, 0))
                o++;
            if (c(1, 2))
                o++;
            if (c(0, 2))
                o++;
            break;

        case 2:
            if (c(0, 1))
                o++;
            if (c(1, 1))
                o++;
            if (c(1, 2))
                o++;
            break;

        default:
            break;
        }
        break;

    case 1:
        switch (b)
        {
        case 0:
            if (c(0, 1))
                o++;
            if (c(2, 1))
                o++;
            if (c(1, 1))
                o++;
            if (c(2, 0))
                o++;
            if (c(0, 0))
                o++;
            break;

        case 1:
            if (c(0, 0))
                o++;
            if (c(1, 0))
                o++;
            if (c(1, 2))
                o++;
            if (c(0, 2))
                o++;
            if (c(0, 1))
                o++;
            if (c(2, 1))
                o++;
            if (c(2, 0))
                o++;
            if (c(2, 2))
                o++;
            break;

        case 2:
            if (c(2, 1))
                o++;
            if (c(1, 1))
                o++;
            if (c(0, 1))
                o++;
            if (c(0, 2))
                o++;
            if (c(2, 2))
                o++;
            break;

        default:
            break;
        }
        break;

    case 2:
        switch (b)
        {
        case 0:
            if (c(2, 1))
                o++;
            if (c(1, 1))
                o++;
            if (c(1, 0))
                o++;
            break;

        case 1:
            if (c(1, 1))
                o++;
            if (c(1, 0))
                o++;
            if (c(1, 2))
                o++;
            if (c(2, 2))
                o++;
            if (c(2, 0))
                o++;
            break;

        case 2:
            if (c(1, 1))
                o++;
            if (c(1, 2))
                o++;
            if (c(2, 1))
                o++;
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
    return o;
}

void write()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << bombs(i, j) << " ";
        }
        cout << endl;
    }
}
void read()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
}

int main()
{
    // int a[3][3];
    read();
    write();
    // cout << m << " " << (int)(m / 30) << endl;
    return 0;
}
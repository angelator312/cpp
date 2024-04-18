#include <iostream>
using namespace std;

void next(int &d, int &m, int &y)
{
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        days[2] = 29;

    if (d < days[m])
    {
        d++;
        return;
    }
    if (m < 12)
    {
        d = 1;
        m++;
        return;
    }
    d = 1;
    m = 1;
    y++;
}

bool ok(int a, int b, int c)
{
    int a1 = a / 10, a2 = a % 10;
    int b1 = b / 10, b2 = b % 10;
    int c1 = c / 1000, c2 = c / 100 % 10, c3 = c / 10 % 10, c4 = c % 10;

    int d = c4 * 10 + c3, m = c2 * 10 + c1;
    int y = b2 * 1000 + b1 * 100 + a2 * 10 + a1;

    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        days[2] = 29;

    if (1 <= m && m <= 12 &&
        1 <= d && d <= days[m] &&
        1 <= y && y <= 9999)
        return true;

    return false;
}

int main()
{
    int d1, m1, y1, d2, m2, y2;
    int n1, n2;

    cin >> n1;
    d1 = n1 / 1000000;
    m1 = n1 / 10000 % 100;
    y1 = n1 % 10000;

    cin >> n2;
    d2 = n2 / 1000000;
    m2 = n2 / 10000 % 100;
    y2 = n2 % 10000;

    int br = 0;
    int d = d1, m = m1, y = y1;
    while (!(d == d2 && m == m2 && y == y2))
    {
        if (ok(d, m, y))
            br++;
        next(d, m, y);
    }

    if (ok(d2, m2, y2))
        br++;
    cout << br << endl;

    return 0;
}
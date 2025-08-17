#include <cmath>
#include <iostream>
#define int LL

using namespace std;
using LL = long long;

LL gcd(LL a, LL b) noexcept {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

pair<LL, LL> extendedEvklid(LL a, LL b) noexcept {
    if (b == 0)
        return {1, 0};
    pair<LL, LL> p = extendedEvklid(b, a % b);
    LL x = p.second;
    LL y = p.first - (a / b) * p.second;
    return {x, y};
}

inline LL add_abs(LL a, LL b) noexcept {
    return abs(a) + abs(b);
}

signed main() {
    LL a, b, c;
    cin >> a >> b >> c;

    int nod = gcd(a, b);
    if (c % nod != 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    a /= nod;
    b /= nod;
    c /= nod;

    pair<LL, LL> p = extendedEvklid(a, b);

    int x0 = p.first * c;
    int y0 = p.second * c;

    int tMinForX = ceil(-1.0 * x0 / b);
    int tMaxForX = floor(1.0 * y0 / a);

    int x1 = x0 + b * tMinForX;
    int y1 = y0 - a * tMinForX;

    int x2 = x0 + b * tMaxForX;
    int y2 = y0 - a * tMaxForX;

    int x3 = x0 + b * (tMinForX - 1);
    int y3 = y0 - a * (tMinForX - 1);

    int x4 = x0 + b * (tMaxForX + 1);
    int y4 = y0 - a * (tMaxForX + 1);

    cerr << x1 << " " << y1 << endl;
    cerr << y2 << " " << y2 << endl;
    cerr << x3 << " " << y3 << endl;
    cerr << x4 << " " << y4 << endl;
    int out1 = min(add_abs(x1, y1), add_abs(x2, y2));
    int out = min(out1, min(add_abs(x3, y3), add_abs(x4, y4)));
    cout << out << endl;
}

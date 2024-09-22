#include <bits/stdc++.h>
using namespace std;

using num = vector<short>;
// 1534
// 4 3 5 1

num to_num(string s)
{
    reverse(s.begin(), s.end());
    num a;
    for (char c : s)
        a.push_back(c - '0');
    return a;
}

string to_string(num x)
{
    string s;
    for (int a : x)
        s += to_string(a);

    reverse(s.begin(), s.end());
    return s;
}

istream &operator>>(istream &is, num &a)
{
    string s;
    is >> s;
    a = to_num(s);
    return is;
}
ostream &operator<<(ostream &out, const num &a)
{
    out << to_string(a);
    return out;
}

num add(num a, num b)
{
    while (a.size() < b.size())
    {
        a.push_back(0);
    }
    while (b.size() > a.size())
    {
        b.push_back(0);
    }
    int prenos = 0, len = a.size();
    for (int i = 0; i < len; i++)
    {
        a[i] = prenos + a[i] + b[i];
        prenos = a[i] / 10;
        a[i] = a[i] % 10;
    }
    while (prenos > 0)
    {
        a.push_back(prenos % 10);
        prenos = prenos / 10;
    }
    return a;
}

num operator+(num &a, num &b)
{
    return add(a, b);
}

num minuss(num a, num b)
{
    while (a.size() < b.size())
    {
        a.push_back(0);
    }
    while (b.size() > a.size())
    {
        b.push_back(0);
    }
    int minus = 0, len = a.size();
    for (int i = 0; i < len; i++)
    {
        int d = a[i] - b[i] - minus;
        if (d >= 0)
            minus = 0;
        else
            d += 10, minus = 1;
        a[i] = d;
    }
    while (a.size() > 1 and a.back() == 0)
        a.pop_back();

    return a;
}

num operator-(num &a, num &b)
{
    return minuss(a, b);
}

num umnozhenie(num a, num b)
{
    int m = a.size();
    int n = b.size();
    num x(m + n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            x[i + j] += a[i] * b[j];

    int c = 0;

    for (int i = 0; i < m + n; i++)
    {
        x[i] += c;
        c = x[i] / 10;
        x[i] = x[i] % 10;
    }

    while (c > 0)
    {
        x.push_back(c % 10);
        c = c / 10;
    }
    while (x.size() > 1 and x.back() == 0)
        x.pop_back();

    return x;
}

num operator+(num a,long long b)
{
    return add(a,to_num(to_string(b)));
}
// num operator-(num a,long long b)
// {
//     return minuss(a,to_num(to_string(b)));
// }




num operator*(num &a, num &b)
{
    return umnozhenie(a, b);
}

num div(num a, long long x)
{
    reverse(a.begin(), a.end());
    long long p = 0;
    for (short &d : a)
    {
        p = p * 10 + d;
        d = p / x;
        p = p % x;
    }
    reverse(a.begin(), a.end());

    while (a.size() > 1 and a.back() == 0)
        a.pop_back();
    return a;
}

num div(num x, num y)
{
    num a(1);
    num b = add(x,to_num("1"));
    while (a + 1 < b)
    {
        num m = div((a + b), 2);
        num s = umnozhenie(m, y);
        if (s <= x)
            a = m;
        else
            b = m;
    }
    return a;
}

num operator/(num &a, num &b)
{
    return div(a, b);
}

num mod(num x,num y)
{
    num q=x/y;
    num r=x-y*q;
    return r;
}

num to_num(long long x)
{
    return to_num(to_string(x));
}

num sqrt(num x)
{
    num a(1);
    num b= add(x,to_num("1"));

    while (a+1<b)
    {
        num m = div((a+b),to_num("2"));
        num s=m*m;
        if(s<=x)a=m;
        else b=m;
    }
    return a;
}


// bool lt(num a,num,b)
// {
//     while (a.size() < b.size())
//     {
//         a.push_back(0);
//     }
//     while (b.size() > a.size())
//     {
//         b.push_back(0);
//     }
    
// }


int main()
{
    num a, b;
    cin >> a;
    cout << sqrt(a) << endl;
}
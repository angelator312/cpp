#include <bits/stdc++.h>
using namespace std;
// using LL = long long;
// const int N = 1e6 + 5;

// #include <bits/stdc++.h>
// using namespace std;


// using num = vector<short>;
// // 1534
// // 4 3 5 1

// num to_num(string s)
// {
//     reverse(s.begin(), s.end());
//     num a;
//     for (char c : s)
//         a.push_back(c - '0');
//     return a;
// }

// num to_num(long long x)
// {
//     return to_num(to_string(x));
// }

// string to_string(num x)
// {
//     string s;
//     for (int a : x)
//         s += to_string(a);

//     reverse(s.begin(), s.end());
//     return s;
// }

// istream &operator>>(istream &is, num &a)
// {
//     string s;
//     is >> s;
//     a = to_num(s);
//     return is;
// }
// ostream &operator<<(ostream &out, const num &a)
// {
//     out << to_string(a);
//     return out;
// }

// num add(num a, num b)
// {
//     while (a.size() < b.size())
//     {
//         a.push_back(0);
//     }
//     while (b.size() > a.size())
//     {
//         b.push_back(0);
//     }
//     int prenos = 0, len = a.size();
//     for (int i = 0; i < len; i++)
//     {
//         a[i] = prenos + a[i] + b[i];
//         prenos = a[i] / 10;
//         a[i] = a[i] % 10;
//     }
//     while (prenos > 0)
//     {
//         a.push_back(prenos % 10);
//         prenos = prenos / 10;
//     }
//     return a;
// }

// num operator+(num &a, num &b)
// {
//     return add(a, b);
// }

// num minuss(num a, num b)
// {
//     while (a.size() < b.size())
//     {
//         a.push_back(0);
//     }
//     while (b.size() > a.size())
//     {
//         b.push_back(0);
//     }
//     int minus = 0, len = a.size();
//     for (int i = 0; i < len; i++)
//     {
//         int d = a[i] - b[i] - minus;
//         if (d >= 0)
//             minus = 0;
//         else
//             d += 10, minus = 1;
//         a[i] = d;
//     }
//     while (a.size() > 1 and a.back() == 0)
//         a.pop_back();

//     return a;
// }

// num operator-(num &a, num b)
// {
//     return minuss(a, b);
// }

// num umnozhenie(num a, num b)
// {
//     int m = a.size();
//     int n = b.size();
//     num x(m + n);
//     for (int i = 0; i < m; i++)
//         for (int j = 0; j < n; j++)
//             x[i + j] += a[i] * b[j];

//     int c = 0;

//     for (int i = 0; i < m + n; i++)
//     {
//         x[i] += c;
//         c = x[i] / 10;
//         x[i] = x[i] % 10;
//     }

//     while (c > 0)
//     {
//         x.push_back(c % 10);
//         c = c / 10;
//     }
//     while (x.size() > 1 and x.back() == 0)
//         x.pop_back();

//     return x;
// }

// num operator+(num a, long long b)
// {
//     return add(a, to_num(to_string(b)));
// }

// num operator*(num &a, num &b)
// {
//     return umnozhenie(a, b);
// }

// num div(num a, long long x)
// {
//     reverse(a.begin(), a.end());
//     long long p = 0;
//     for (short &d : a)
//     {
//         p = p * 10 + d;
//         d = p / x;
//         p = p % x;
//     }
//     reverse(a.begin(), a.end());

//     while (a.size() > 1 and a.back() == 0)
//         a.pop_back();
//     return a;
// }

// num operator/(num &a, long long x)
// {
//     return div(a, x);
// }

// num operator/(num a, int x)
// {
//     return div(a, 1LL * x);
// }
// bool operator<=(num a, num x)
// {
//     string s = to_string(a);
//     string t = to_string(x);
//     if (s.size() < t.size())
//         return true;
//     if (s.size() > t.size())
//         return false;

//     return s <= t;
// }
// num div(num x, num y)
// {
//     num a(1);
//     num b = add(x, to_num("1"));
//     while (a + 1 < b)
//     {
//         num m = div((a + b), 2);
//         num s = umnozhenie(m, y);
//         // reverse(s.begin(),s.end());
//         // cout<<s<<endl;
//         // cout<<x<<endl;

//         if (s <= x)
//         {
//             // cout<<1<<endl;
//             a = m;
//         }
//         else
//             b = m;
//     }
//     // cout << a << endl;
//     // cout << b << endl;
//     return a;
// }

// num operator/(num &a, num &b)
// {
//     return div(a, b);
// }

// bool operator<(num a, num b)
// {
//     string s = to_string(a);
//     string t = to_string(b);
//     if (s.size() < t.size())
//         return false;
//     if (s.size() > t.size())
//         return true;

//     return s < t;
// }

// long long sqrtnum(num x)
// {
//     long long a = 0;
//     long long b = (1LL << 60) + 1;

//     while (a < b - 1)
//     {
//         long long m = a + (b - a) / 2;
//         cout << b << endl;
//         cout << a << endl;
//         cout << m << endl;
//         num s = to_num(m * m);
//         if (s < x)
//         {
//             a = m;
//         }
//         else
//             b = m;
//     }

//     return a;
// }

// num sqrt(num x)
// {
//     num a(1);
//     num b = add(x, to_num("1"));

//     while (a + 1 < b)
//     {
//         num m = div((a + b), to_num("2"));
//         num s = m * m;
//         if (s <= x)
//             a = m;
//         else
//             b = m;
//     }
//     return a;
// }

// num mod(num x,num y)
// {
//     num q=x/y;
//     num r=x-y*q;
//     return r;
// }

// num operator%(num &a, num &b)
// {
//     return mod(a, b);
// }


// num operator%(num &a, int &b)
// {
//     return mod(a,to_num(b));
// }


// num factorieli[N];
// int reshenia[N];
// int resheto[N];


// num factoriel(int a)
// {
//     if (factorieli[a])
//         return factorieli[a];
//     else
//     {
//         num b = a * factoriel(a - 1);
//         factorieli[a] = b;
//         return b;
//     }

// }

// int stepeni(num a)
// {
//     // return resheto[a];
//     int br = 0;
//     while (a % 2 == 0)
//     {
//         br++;
//         a /= 2;
//     }

//     for (int i = 3; i * i < a; i += 2)
//     {
//         while (a % i == 0)
//         {
//             br++;
//             a =a/ i;
//         }
//     }
//     return br + 1;
// }

// void reshetoNaEratosten()
// {
//     for (int j = 2 * 2; j < N; j += 2)
//     {
//         int d = j;
//         while (d % 2 == 0)
//         {
//             resheto[j]++;
//             // cout << resheto[j] << endl;
//             d /= 2;
//         }
//     }
//     for (int i = 3; i < N; i += 2)
//     {
//         if (resheto[i])
//             continue;
//         for (int j = i * 2; j < N; j += i)
//         {
//             int d = j;
//             while (d % i == 0)
//             {
//                 resheto[j]++;
//                 // cout << resheto[j] << endl;
//                 d /= i;
//             }
//         }
//     }
// }

int main()
{
//     factorieli[0].push_back(1);
//     int n;
//     cin >> n;
//     // reshetoNaEratosten();
//     for (int i = 0; i < n; i++)
//     {
//         int e;
//         cin >> e;
//         if (reshenia[e])
//         {
//             cout << reshenia[e] << " ";
//             continue;
//         }
//         int a = stepeni(factoriel(e));
//         reshenia[e] = a;
//         cout << a << " ";
//     }

//     cout << endl;
}
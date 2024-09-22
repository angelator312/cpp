#include <bits/stdc++.h>
using namespace std;

unsigned long long factoriel(int n)
{
    if (n <= 1)
        return 1;
    return factoriel(n - 1) * n;
}
//=---------------------------------=
int gcd(int a, int b)
{
    if (a - b == 0)
        return a;
    if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}
//=---------------------------------=
int sumD(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + sumD(n / 10);
}
//=---------------------------------=
bool isChetno(int n)
{
    if (n == 1)
        return 0;
    if (n == 0)
        return 1;
    return isChetno(n - 2);
}
//=---------------------------------=
bool isChetnoOp(int n)
{
    if(n<=10) return isChetno(n);
    if (n == 1)
        return 0;
    if (n == 0)
        return 1;
    return isChetno(n - 10);
}
//=---------------------------------=
bool isChetnoOptimized(int n,int d)
{
    // cout<<n<< " "<<d<<endl;
    if(n<d) return isChetnoOptimized(n,d/10);
    if (n == 1)
        return 0;
    if(n == 0)
        return 1;
    return isChetnoOptimized(n - d,d);
}
//=---------------------------------=
bool isProsto2(int x,int i)
{
    // cout<<n<< " "<<d<<endl;
    if(i*i>x)return 1;
    if(x%i==0) return 0;
    return isProsto2(x,i+2);
}
//=---------------------------------=
bool isProsto(int x)
{
    // cout<<n<< " "<<d<<endl;
    if(x==2)return 1;
    if(x%2==0) return 0;
    return isProsto2(x,3);
}
//=---------------------------------=
int isHereK(int x,int k)
{
    // cout<<n<< " "<<d<<endl;
    if(x)return 1;
    if(x%10==k) return 1+isHereK(x/10,k);
    return isProsto2(x,3);
}
//=---------------------------------=
const int N=1e9;
int masiv[N];
int fibonachi(int n)
{
    if(masiv[n])return masiv[n];
    if(n==1)return 1;
    if(n<=0)return 0;
    // cout<<n<< " "<<d<<endl;
    return fibonachi(n-1)+fibonachi(n-2);
}
//=---------------------------------=
// int powerX2(float x,int n)
// {
//     if(n==0)return 1;
//     // cout<<n<< " "<<d<<endl;
//     return n*powerX(x,n-1);
// }
// //=---------------------------------=
// int powerX(int x,int n)
// {
//     if(n==0)return 1;
//     if(x==1)return 1;
//     if(x==-1)return (n%2*2)-1;
//     if(x==0)return 0;
//     if(x<0)x=(1.0/x);
//     // cout<<n<< " "<<d<<endl;
//     return powerX2(x,n);
// }
// //=---------------------------------=
int main()
{
    int a, b;
    cin >> a;
    // cin >> b;
    cout << fibonachi(a) << endl;
    // cout << fibonachi(a) << endl;
    // cout << isProsto(a) << endl;
    // if (isChetnoOptimized(a,2000))
    // {
    //     cout <<"chetno" <<endl;

    // }else
    //     cout <<"nechetno" <<endl;

    // cout << sumD(a) << endl;
    // cout << gcd(a, b) << endl;
    // if (n > 20)
    // {
    //     cout << "n is invalid" << endl;
    // }
    // else
    //     cout << factoriel(n) << endl;
}
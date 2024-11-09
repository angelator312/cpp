#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int f1(double a)
{
    // a/=1000;
    if (a <= 5)
    {
        return 400;
    }
    else if (a <= 10)
    {
        return 700;
    }
    else if (a<=20)
    {
        return 12000;
    }else if(a<=30){
        return 17000;
    }else{
        return floor(a)*57;
    }
};
int f2(double a)
{
    // a/=1000;
    if (a <= 2)
    {
        return 90+floor(a)*90;
    }
    else if (a <= 5)
    {
        return 100+floor(a)*85;
    }
    else if (a<=20)
    {
        return 125+80*floor(a);
    }else if(a<=40){
        return 325+70*floor(a);
    }else{
        return 925+floor(a)*55;
    }
}
int main()
{
    int a, b, t, mn;
    cin >> a >> b;
    mn = f1(a/1000.0) + f1(b/1000.0);
    t = f1(a/1000.0) + f2(b/1000.0);
    if (t < mn)
    {
        swap(t, mn);
    }
    t = f2(a/1000.0) + f2(b/1000.0);
    if (t < mn)
    {
        swap(t, mn);
    }
    int m=mn%100;
    cout << mn / 100 << "." << m/10<<m % 10 << endl;
    cout<<(bool)(5.01>5)<<endl;
}
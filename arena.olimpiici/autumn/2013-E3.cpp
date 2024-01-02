#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int main()
{
    int a,b,c;
    char z;
    cin >> z;
    a=z-'0';
    cin >> z;
    b=z-'0';
    cin >> z;
    c=z-'0';

    cout <<max(max(a*b+c,a+b*c),max(a*b*c,a+b+c)) << endl;
    return 0;
}
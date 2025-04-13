#include <iostream>
using namespace std;
int main()
{
    long long n;
    int x, n0,out;
    cin >> n >> x;
    n0 = n % 6;
    // cout << "n0 = " << n0 << endl;
    // cout << "x = " << x << endl;
    if (x == 0)
    {
        if (n0 == 1 || n0 == 2 )
            out = 1;
        if (n0 == 3  || n0 == 4 )
            out = 2;
        if ( n0==5 || n0 == 0 )
            out = 0;
    }
    if (x == 1){
        if (n0 == 0 || n0 == 3)
            out = 1;
        if (n0 == 2 || n0 == 5)
            out = 2;
        if (n0 == 1 || n0 == 4)
            out = 0;
    }
    if (x == 2){
        if (n0 == 1 || n0 == 2 || n0 == 3 )
            out = 0;
        if (n0 == 0  )
            out = 2;
        if ( n0 ==4 ||n0 ==5)
            out = 1;
    }

    cout << out << endl;
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
    long long ch,out=0;
    cin >> ch;

    for (long long j = 2; j<=ch/2; j++)
    {
        if (ch%j==0)
        {
            out+=j;
            cout<<"for del="<<j<<endl;
        }
    }
    out++;

    cout << out<< endl;
    if(out>ch)cout<<"YES"<< endl;
    else cout<<"NO"<< endl;
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;




int main()
{
    long long a,b;
    cin>>a>>b;

    int br=int(sqrt(b))-int(sqrt(a-1));

    cout<<br<<endl;

    return 0;
}


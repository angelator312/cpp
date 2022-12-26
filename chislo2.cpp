#include <iostream>
using namespace std;
int main()
{
    int a,b,b2,b3,b4;
    //  int a, b;
    cin >> a;
    if(a==2){
        b3=(13/3)*a+(16%a)*2;
        cout <<"3-b "<<b3 << endl;
        b4=(21-a)/3+(21-a)%4;
        cout <<"4-b "<<b4 << endl;
        return 0;
    }
    b=3*a%4+(a+6)/5-20%(a-2);
    cout <<"1-b "<<b << endl;
    b2=a+8/3-(12+a)/5;
    cout <<"2-b "<<b2 << endl;
    b3=(13/3)*a+(16%a)*2;
    cout <<"3-b "<<b3 << endl;
    b4=(21-a)/3+(21-a)%4;
    cout <<"4-b "<<b4 << endl;
    return 0;

}

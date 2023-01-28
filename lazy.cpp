#include <iostream>

using namespace std;
int main()
{
    int n;
    cin >>n;
    char cs[n];
    cin.read(cs,2);//чете нов ред и  един интервал
    cin.read(cs,n);
    for(int i=0;i<n;i++)
    {
        char e = cs[i];
        //cout<<"char ="<<e<<" ";
        if(e!='a'&&e!='b'&&e!='d'&&e!='e'&&e!='g'&&e!='o'&&e!='p'&&e!='q'&&e!=' ')
            cout<<e;
    }
    cout<<endl;
    return 0;
}


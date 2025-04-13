#include <iostream>
using namespace std;
int main()
{
    long plus=0,pos=1,fi;
    cin>>fi;
    for (int i = 1;; i++){
        pos=pos+plus;
        plus=plus+2;
        if (i==fi)
            break;
    }
    
    cout << pos << endl;
    return 0;
}
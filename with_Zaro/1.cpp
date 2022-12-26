#include "types.hpp"

int main(){
    int a[4];
    int k=1;
    for (int i = 0; i < 4; i++)
    {
        cout << a[i] << endl;
    }
    k+=6;
    cout <<a[k]<< endl;
    return 0;
}
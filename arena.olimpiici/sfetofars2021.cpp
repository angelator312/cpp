#include <iostream>
using namespace std;
int main(){
    int n,l,z=0;
    cin>>n>>l;
    for (int i = 0; i < n; i++){
        int d,r,g,ci;
        cin>>d>>r>>g;
        ci = d%(r+g);
        if(ci>r) z=0;
        else z=r-ci;
    }
    cout << l+z<<endl;
    
    return 0;
}
#include <iostream>
using namespace std;
int main(){
    int n,l,z=0;
    cin>>n>>l;
    for (int i = 0; i < n; i++){
        int d,r,g,ci;
        cin>>d>>r>>g;
        ci = (d+z)%(r+g);
        if(ci<r) z+=r-ci;
        // cout <<ci<<" "<<r<<" " <<g<<" "<<z<<endl; 
    }
    cout << l+z<<endl;
    
    return 0;
}
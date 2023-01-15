#include <iostream>
using namespace std;
int main(){
    int n,pe=-1,r=0,l=1,ml=0;
    cin>>n;
    for (int i = 0; i < n; i++){
        int e;
        cin>>e;
        if (pe !=-1){
            if (pe+1!=e){r++;l=1;}
            else l++;
            if(l>ml)ml=l;
            // cout << l <<endl;
        }
        pe=e;
    }
    cout << r<<" "<<ml <<endl;
    
    return 0;
}
#include<iostream>
using namespace std;
typedef  long long ul;
int main(){
    ul a,b;
    cin>>a>>b;
    if(a>b){
        swap(a,b);
    }
    ul bm=b-a,am=a,br=1;
    while(am>0 && bm>0){
        if(am==1||bm==1){
            br+=max(am,bm);
            break;
        }
        if(am>bm){
            am-=bm;
        }else{
            bm-=am;
        }
        br++;
    }
    cout<<br<<endl;
    return 0;
}

#include<iostream>
using namespace std;
int kuk12(int &k, int h,int m,int h2,int m2){
    if(h==0&& m<=30 && h2==12&& m2>30){
        k+=90;return k;
    }
    k+=h2-h;k++;
    if(m2<30)k--;
    if(m>30)k--;
    if(((h2-h)+1)%2==1){
        k+=h2;h2--;
    }
    // cout<<k<<endl;
        k+=(h+h2)*((h2-h)+1)/2;
    // cout<<k<<endl;
    if(m>0)k-=h;
    // cout<<k<<endl;
    return k;
}
int main(){
    int h,m,h2,m2,k=0;
    cin >> h >> m >> h2 >>m2;
    if(h2<h){
        kuk12(k,h,m,12,59);
        k+=90;
        kuk12(k,1,0,h2,m2);
    }else{
        if(h2>12){
            kuk12(k,h,m,12,59);
            kuk12(k,0,0,h2-12,m2);

        }else
        kuk12(k,h,m,h2,m2);
    }
    cout<<k<<endl;
    
}
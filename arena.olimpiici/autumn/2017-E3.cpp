//100 t.
#include <iostream>
using namespace std;
int main(){
    int n,a,b,c,r=0;
    cin>>n>>a>>b>>c;
    n--;
    // A==Заек В==Бухал С==Йори;
    char k='A';
    for (; n>0; n--)
    {
        if (k=='A')
        {
            int m=min(a,b);
            if (m==a)
            {
                k='B';
            }else{
                k='C';
            }
            r+=m;
            
        }else if (k=='B')
        {
            int m=min(a,c);
            if (m==a)
            {
                k='A';
            }else{
                k='C';
            }
            r+=m;
        }else{
            int m=min(b,c);
            if (m==b)
            {
                k='A';
            }else{
                k='B';
            }
            r+=m;
        }
    }
    cout<<r/100<<" "<<r%100<<endl;
}
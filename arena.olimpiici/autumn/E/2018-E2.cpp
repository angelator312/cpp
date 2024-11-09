#include <iostream>
using namespace std;
int main()
{
    int t1, t4,t2, t3, t5, t6;
    int br,mk,mp,out;
    cin>>t1>>t2>>t3>>t4>>t5>>br>>t6;
    mk=t1*60+t2;
    mp=t4*60+t5;
    out=mk-(mp+t3+(br+1)*t6+10);
    // cout<<out<<endl;
    int outh=out/60,outm=out%60;
    cout<<outh/10<<outh%10<<" "<<outm/10<<outm%10<<endl;
    return 0;
}
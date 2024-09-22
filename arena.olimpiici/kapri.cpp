#include <iostream>
#include <numeric>
using namespace std;
int main(){
    int N,K,br=0;
    cin>>N;
    for (int i = 0; i < N; i++)
    { int e;
        cin>>e;
        int ek=e*e;
        int s=to_string(e).size();
        string pe2=to_string(ek);
        int sub=stoi(pe2.substr(0,pe2.size()-s)),sub2=stoi(pe2.substr((pe2.size()-s)-1,s));
        if(sub+sub2==e)br++;
    }
    cout<<br<<endl;
    return 0;
}
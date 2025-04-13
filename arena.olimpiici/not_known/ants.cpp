#include <iostream>
using namespace std;

int main() {
    int T;
    string a1,a2,all;
    cin >> a1 >> a2>>T;
    all=string(a1.rbegin(),a1.rend())+a2;
    short fb[27]{};
    for(int i=0;i<a2.size();i++){
        fb[a2[i]-'A']=1;
    }
    for (int i = 1; i <= T; i++)
    {
        for (int j = 0; j <= all.size()-2; j++)
        { short e=all[j],e1=all[j+1];
            if(j+1==all.size())break;
            if(fb[e-'A']<fb[e1-'A']){
                swap(all[j],all[j+1]);
                j++;
            }
        }
        
    }
    cout<<all<<endl;
    return 0;
    
}
#include<iostream>
using namespace std;
typedef  long long ul;
int main()
{
    ul br=0,i=1,brp=-1;
    string s;
    cin>>s;
    char p=s[0];
    while(true)
    {
        if(i==s.size())
        {
            if(br==brp){
                    //cout<<br<<" "<<brp<<endl;
                    break;
            }
            i=1;
            p=s[0];
            brp=br;
        }

        if(p=='1'&&s[i]=='0')
        {
            s[i-1]='0';
            s[i]='1';
            //cout<<i<<" s:"<<s<<endl;
            br++;
        }

        p=s[i];
        i++;
    }
    cout<<br<<endl;
    return 0;
}

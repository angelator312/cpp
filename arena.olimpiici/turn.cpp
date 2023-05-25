#include<iostream>
using namespace std;
typedef  long long ul;
char b[1250000];
inline bool getbit(int bit){
    return (b[bit/8] &(1<<bit%8))?1:0;
}
inline void setbit(int bit,bool v){
    if(v){
        b[bit/8] = b[bit/8] | (1<<bit%8);
    }else{
        b[bit/8] = b[bit/8] & (~(1<<bit%8));
    }
}
int main()
{
    ul br=0,i=1,brp=-1,bits=0;
    char c;
    while(true){
        cin>>c;
        if((c!='1'&&c!='0')||cin.eof())break;
        setbit(bits,c-'0');
        bits++;
    }
    //cout<<"stop"<<endl;
    //cout<<bits<<endl;
    //for(i=0;i<bits;i++){
    //    cout<<getbit(i)<<endl;
    //}
    char p=getbit(0);
    while(true)
    {
        if(i==bits)
        {
            if(br==brp){
                    //cout<<br<<" "<<brp<<endl;
                    break;
            }
            i=1;
            p=getbit(0);
            brp=br;
        }

        if(p==1&&getbit(i)==0)
        {
            setbit(i,1);
            setbit(i-1,0);
            //cout<<i<<" e:"<<getbit(i)<<endl;
            br++;
        }

        p=getbit(i);
        i++;
    }
    cout<<br<<endl;
    return 0;
}

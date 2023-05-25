#include <iostream>
using namespace std;
int main()
{
    long long ad=0;
    int ah=0,am=0,as=0,h=0,m=0,s=0,br=1,os,om,oh,od=0;
    string time,alarm,sega="s";
    getline(cin,time);
    getline(cin,alarm);
    h=(time[0]-'0')*10+time[1]-'0';
    m=(time[3]-'0')*10+time[4]-'0';
    s=(time[6]-'0')*10+time[7]-'0';
    for(long long i=alarm.size()-1; i>=0; i--)
    {
        int e=alarm[i]-'0';
        //cout<<e<<" s:"<<sega<<endl;
        if(alarm[i]==':')
        {
            if(sega=="s")
            {
                sega="m";
                br=1;
                continue;
            }
            if(sega=="m")
            {
                sega="h";
                br=1;
                continue;
            }
        }
        if(sega=="s")
        {
            as+=e*br;
            //cout<<as<<endl;
            if(s>=60)
            {
                am+=as/60;
                as=as%60;
            }
            br*=10;
        }
        if(sega=="m")
        {
            am+=e*br;
            if(am>=60)
            {
                ah+=am/60;
                am=am%60;
            }
            br*=10;
        }
        if(sega=="h")
        {
            ah+=e*br;
            if(ah>=24)
            {
                ad+=ah/24;
                ah=ah%24;
            }
            br*=10;
        }
    }
    int om2=0,oh2=0,od2=0;
    //cout<<s<<"---------"<<as<<endl;
    os=(as+s)%60;
    //cout<<os<<endl;
    om=(as+s)/60;
    //cout<<om<<endl;
    om+=(am+m)%60;
    if(om>=60){om2=om/60;om=om%60;}
    //cout<<om<<endl;
    oh=(am+m)/60+om2;
    //cout<<oh<<endl;
    oh+=(ah+h)%24;
    if(oh>=24){od2=oh/24;oh=oh%24;}
    //cout<<os<<endl;
    od=(ah+h)/24+ad+od2;
    //cout<<od<<endl;
    if(od==0)
    {
        cout<<oh/10<<oh%10<<":"<<om/10<<om%10<<":"<<os/10<<os%10<<endl;
    }
    else
    {
        cout<<oh/10<<oh%10<<":"<<om/10<<om%10<<":"<<os/10<<os%10<<"+"<<od<<" days"<<endl;
    }

    ///cout<<ad<<":"<<ah<<":"<<am<<":"<<as<<endl;
    return 0;
}

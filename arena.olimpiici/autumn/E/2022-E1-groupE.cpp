// TEST_ZIP: https://arena.olimpiici.com/api/public/problems/1853/zip?download=true
#include <iostream>
#define endl "\n"
#if 0
#define P(a) cout<<a<<endl
#else
#define P(a) 
#endif 
using namespace std;
string posledno(int prod,bool b=false)
{
    if (prod < 4)
    {
        if (prod == 1)
        {
            return "1E";
        }
        else if (prod == 2)
        {
            return "1F";
        }
        else if(prod==0){
            return "1D";
        }
        else
        {
            return "2A";
        }
    }
    else if (prod >= 118)
    {
        if (b && prod==118)
        {
            return "21E";
        }else
            return "full";
    }
    else if (prod == 117)
    {
        return "21D";
        
    }
    else
    {int op1=0;
    char c='*';
        if((prod-3)/6>(prod-4)/6){
            op1=(prod-3)/6+1;
        }else{
            op1=(prod-3)/6+2;
        }
        if ((prod-3)%6==0)
        {
            c='A';
            op1++;
            if (op1==21)
            {
                c='D';
            }
            
        }else{
            c=(((prod-3) % 6) + 'A');
        }
        
        return (string)(to_string(op1) + c);
    }
}
int main()
{
    int prod, slL, poslL,sluzhebnoRow, poslRow;
    string sluzhebno, out = "";
    cin >> prod >> sluzhebno;
    string posl = posledno(prod);
    slL = sluzhebno.length();
    poslL = posl.length();
    P(posl);
    // P(slL);
    if (slL - 1 == 2)
    {
        sluzhebnoRow =( sluzhebno[0]- '0')*10 + sluzhebno[1]- '0';
        // P(sluzhebno[0]- '0') ; 100 20F
    }
    else
    {
        sluzhebnoRow = sluzhebno[0]- '0';
    }
    if (poslL - 1 == 2)
    {
        poslRow = (posl[0]- '0')*10 + posl[1]- '0';
    }
    else
    {
        poslRow = posl[0]- '0';
    }
    if (sluzhebnoRow < poslRow)
    {
        P(1);
        cout << posledno(prod + 1,true) << endl;
    }
    else if (sluzhebnoRow == poslRow)
    {
        int slI = sluzhebno[slL - 1] - 'A', poslI = posl[slL - 1] - 'A';
        if (slI <= poslI)
        {
            P(2);
            cout << posledno(prod + 1,true) << endl;
        }
        else
        {
            cout << posl << endl;
        }
    }
    else
    {
        cout << posl << endl;
    }

    return 0;
};

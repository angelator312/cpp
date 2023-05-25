#include <iostream>
using namespace std;
int monos[10];
bool mon(int in, int monoi)
{
    if (monoi == 10 || in <= 0)
        return false;
    string sin = to_string(in);
    int c = sin.size(), mono, mz = 0;
    bool b = false;
    char p = sin[0];
    if(in<10&&monoi==9)
    {
        monos[monoi] = in;
        return true;
    }
    for (int i = 1; i < c; i++)
    {
        if (sin[i] - '0' < p - '0')
        {
            b = false;
            break;
        }
    }
    //cout << "(" << monoi << ")p:make:mono " << mz << " " << sin << endl;
    if(sin=="1"&&monoi<9)return false;
    if (b)
    {
        mono = p - '0';
        mz = mono;
        for (int i = 1; i < c; i++)
            mono = mono * 10;
    }
    else
    {
        mz = p - '0' - 1;
        mono = mz;
        if (mz > 0)
        {
            for (int i = 1; i < c; i++)
                mono = mono * 10 + mz;
        }
        else
        {
            mz = 9;
            mono = mz;
            c--;
            for (int i = 1; i < c; i++)
                mono = mono * 10 + mz;
        }
    }
    //cout << "(" << monoi << ")made:mono:" << mono << " c:" << c << endl;
    if (c <= 0)
        return false;
    while (!mon(in - mono, monoi + 1))
    {

        mz--;
        mono=mz;
        //cout << "(" << monoi << ")w:--makes mono mz:" << mz << " mono:" << mono << " c:" << c << endl;
        if (c <= 0)
            return false;
        if (mz > 0)
        {
            for (int i = 1; i < c; i++)
                mono = mono * 10 + mz;
        }
        else
        {
            mz = 9;
            mono = mz;
            c--;
            if (c <= 0)
                return false;
            for (int i = 1; i < c; i++)
                mono = mono * 10 + mz;
        }
        //cout << "(" << monoi << ")w:made mono mz:" << mz << " mono:" << mono << " c:" << c << endl;
    }
    monos[monoi] = mono;
    return true;
}
int main()
{
    int n;
    cin >> n;
    mon(n, 0);
    for(int i=0; i<9; i++)
    {
        cout<<monos[i]<<" ";
    }
    cout<<monos[9]<<endl;
    return 0;
}

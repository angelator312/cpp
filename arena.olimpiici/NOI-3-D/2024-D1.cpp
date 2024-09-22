#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 1;
const int M = 5e3 + 1;
bool misheni[N][M]; // N-x; N-y;

int shot(int x,int y,int a,int b)
{
    int br=0;
    for (int x2 = x,y2=y; x2 < b &&y2<a ; x2+=x,y2+=y) // -x
    {
        if(!misheni[x2][y2])
        {
            misheni[x2][y2]=1;
            br++;
        }
    }
    return br;
}

int main()
{
    int a, b;
    cin >> a >> b;
    int br = 2, tr = a * b - (a + b-1); // br==2, zashtoto sme vzeli dve redici
    // cout<<tr<<endl;
    for (int x = 1; x < b; x++)       // -x
    {
        for (int y = 1; y < a; y++) // -x
        {
            if(misheni[x][y])continue;
            int e=shot(x,y,a,b);
            if(e>0)
                br++,tr-=e;
            if(tr<=0)break;
            // cout<<tr<<endl;
        }
    }

    cout << br << endl;
    return 0;
}
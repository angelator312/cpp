// TEST_ZIP: https://arena.olimpiici.com/api/public/problems/1338/zip?download=true
#include <iostream>
using namespace std;
int main()
{
    int h = 0, m = 0, n;
    cin >> n;
    // cout<<n<<endl;
    for (int i = 0; i < n; i++)
    {
        int e1, e2;
        cin >> e1 >> e2;
        h += e1 + e2 / 60;
        m += e2 % 60;
    }
    int SD1=(h*60+m),SD2=SD1;
    if (SD1%240)
    {
        SD1=((SD1/240)+1);
    }else{
        SD1=(SD1/240);
    }

    if (SD2%180)
    {
        SD2=((SD2/180)+1);
    }else{
        SD2=(SD2/180);
    }
    if (SD1>SD2)
    {
        
    }else{
        int st=0;
        if (m%240==180)
        {
            
        }
        
    }
    
    // cout<<SD1<<" "<<SD2<<endl;
    string out=to_string(min(SD1,SD2)/100)+"."+to_string(min(SD1,SD2)%100);
    cout<<out<<endl;
    return 0;
}
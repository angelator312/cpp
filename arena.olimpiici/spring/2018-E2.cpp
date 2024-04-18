#include <iostream>
using namespace std;
using LL = long long;
int main()
{
    int n;
    cin >> n;
    int preM[n + 2]{};

    for (int i = 1; i <= n; i++)
    {
        cin >> preM[i];
        preM[i] += preM[i - 1];
    }
    
    for(int brRedici = 2;brRedici <= n;)
    {
        
        // pyrvi ukazatel
        for (int j = 1; j <= n; j++)
        {
            
            int e = preM[j] - 0, posl = j + 1, seg = j + 1;
            // "e" e taka , za da zapochva redicata ot 1 element
            bool da = true;

            for (int k = 0; k <= brRedici - 2; k++)
            {
                if(k==brRedici)seg=n;

                while (seg < n && preM[seg] - preM[posl - 1] < e)
                    seg++;

                // if (seg > n)
                // {
                //     da = false;
                //     break;
                // }
                //cout << "[" << posl << "] do [" << seg << "] e " << e << endl;
                if (k == brRedici - 2 && seg < n)
                {
                    da = false;
                    break;
                }
                if (preM[seg] - preM[posl - 1] == e)
                    posl = seg + 1;
                else
                {
                    da = false;
                    break;
                }
            }

            if (da)
            {
                cout << brRedici << endl;
                return 0;
            }
        }
        brRedici++;
        if(brRedici>n)break;
        if(brRedici>n/2)brRedici=n;
    }

    cout << 0 << endl;
}
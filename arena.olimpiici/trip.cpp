#include <iostream>
#include <climits>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    long n,m,minSum=LONG_MAX,r;
    cin >> n >> m;
    int t[n];
    for (int i = 0; i < n; i++)
        cin >> t[i];
    long sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if(i>=m)
        {
            if(sum <= minSum ) {minSum = sum;r=i-m;}
            ///cout<<"container i:"<<i<<" sum:"<<sum<<endl;
            if(i==n)break;
            sum+=t[i]-t[i-m];
        }
        else
            sum += t[i];

    }
    cout <<r << endl;
}

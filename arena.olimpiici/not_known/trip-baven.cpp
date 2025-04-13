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
    for (int i = 0; i <= n-m; i++)
    {
        long sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += t[i+j];
        }
        if(sum <= minSum ) {minSum = sum;r=i;}
    }
    cout <<r << endl;
}

#include <iostream>
using namespace std;
int main()
{
    int n, m, ch = 0, pe;
    cin >> n >> m;
    pe=n;
    for (int i = 1;; i++){
        int n2 = pe, ch = pe;
        while (n2 != 0){
            int d = n2 % 10;
            n2 = n2 / 10;
            ch += d;
        }
        // cout << ch << endl;
        if (ch>m) {
            cout << i << endl;
            break;
        }
        pe = ch;
    }

    return 0;
}
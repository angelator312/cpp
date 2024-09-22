#include <iostream>
using namespace std;
int main()
{
    int n, p = -1, q = -1, m = -1;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        if (A[i - 1] < A[i] && A[i + 1] < A[i])
        {
            p = i;
            break;
        }
    for (int i = p; i < n && i > 0; i++)
        if (A[i - 1] > A[i] && A[i + 1] > A[i])
        {
            q = i;
            break;
        }
    for (int i = q; i < n && i > 0; i++)
        if (A[i - 1] < A[i] && A[i + 1] < A[i])
        {
            m = i;
            break;
        }
    for (int i = m + 1; i < n && i > 0; i++)
        if (A[i] >= A[m])
        {
            p = -1;
            break;
        }
    if (p == -1 || (q == -1 ||( m == -1 || m==n-1)))
    {
        cout << "0" << endl;
    }
    else
        cout << p << " " << q << " " << m << endl;
    return 0;
}
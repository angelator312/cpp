#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;
int M, N, t[4], o = 0, mx, mn;
bool ne[4] = {0, 0, 0, 0};
// ne[0] = 0, ne[1] = 0, ne[2] = 0, ne[3] = 0;
bool mne[4] = {0, 0, 0, 0};
// mne[0] = 0, mne[1] = 0, mne[2] = 0, mne[3] = 0;
int max2()
{
    if (ne[0])
    {
        if (ne[1])
        {
            if (ne[2])
            {
                if (ne[3])
                    return 0;
                else
                    return t[3];
            }
            else
            {
                if (ne[3])
                    return t[2];
                else
                    return max(t[3], t[2]);
            }
        }
        else
        {
            if (ne[2])
            {
                if (ne[3])
                    return t[1];
                else
                    return max(t[3], t[1]);
            }
            else
            {
                if (ne[3])
                    return max(t[2], t[1]);
                else
                    return max(max(t[3], t[2]), t[1]);
            }
        }
    }
    else
    {
        if (ne[1])
        {
            if (ne[2])
            {
                if (ne[3])
                    return t[0];
                else
                    return max(t[0], t[3]);
            }
            else
            {
                if (ne[3])
                    return t[2];
                else
                    return max(t[3], max(t[0], t[1]));
            }
        }
        else
        {
            if (ne[2])
            {
                if (ne[3])
                    return max(t[1], max(t[0], t[1]));
                else
                    return max(max(t[0], t[1]), t[3]);
            }
            else
            {
                if (ne[3])
                    return max(max(t[0], t[1]), t[2]);
                else
                    return max(max(t[3], t[2]), max(t[0], t[1]));
            }
        }
    }
}

int min2()
{
    if (mne[0])
    {
        if (mne[1])
        {
            if (mne[2])
            {
                if (mne[3])
                    return -1;
                else
                    return t[3];
            }
            else
            {
                if (mne[3])
                    return t[2];
                else
                    return min(t[3], t[2]);
            }
        }
        else
        {
            if (mne[2])
            {
                if (mne[3])
                    return t[1];
                else
                    return min(t[3], t[1]);
            }
            else
            {
                if (mne[3])
                    return min(t[2], t[1]);
                else
                    return min(min(t[3], t[2]), t[1]);
            }
        }
    }
    else
    {
        if (mne[1])
        {
            if (mne[2])
            {
                if (mne[3])
                    return t[0];
                else
                    return min(t[0], t[3]);
            }
            else
            {
                if (mne[3])
                    return t[2];
                else
                    return min(t[3], min(t[0], t[1]));
            }
        }
        else
        {
            if (mne[2])
            {
                if (mne[3])
                    return min(t[1], min(t[0], t[1]));
                else
                    return min(min(t[0], t[1]), t[3]);
            }
            else
            {
                if (mne[3])
                    return min(min(t[0], t[1]), t[2]);
                else
                    return min(min(t[3], t[2]), min(t[0], t[1]));
            }
        }
    }
}

void updatemx()
{
    if (mx == t[0])
    {
        ne[0] = 1;
        mx = max2();
    }
    else if (mx == t[1])
    {
        ne[1] = 1;
        mx = max2();
    }
    else if (mx == t[2])
    {
        ne[2] = 1;
        mx = max2();
    }
    else
    {
        ne[3] = 1;
        mx = max2();
    }
    mx = max2();
}

void updatemn()
{
    if (mn == t[0])
    {
        mne[0] = 1;
        mn = min2();
    }
    else if (mn == t[1])
    {
        mne[1] = 1;
        mn = min2();
    }
    else if (mn == t[2])
    {
        mne[2] = 1;
        mn = min2();
    }
    else
    {
        mne[3] = 1;
        mn = min2();
    }
    mn = min2();
}

int main()
{
    cin >> M >> N >> t[0] >> t[1] >> t[2] >> t[3];
    mx = max2();
    mn = min2();

    while (N == mx)
    {
        updatemx();
        o++;
    }

    if (M >= 4)
    {
        int mXN = mx + mn;
        while (mXN == N)
        {
            cout << mXN << endl;
            updatemx();
            updatemn();
            o++;
            mXN = mx + mn;
        }

        while (mXN < N)
        {
            if (mx == mn)
            {
                int mnB = 0, mxB = 0;
                for (int i = 0; i < 4; i++)
                {
                    int e = t[i];

                    // cout<<e<<endl;
                    if (ne[i] || mne[i])
                        continue;
                    if (e + mXN <= N)
                    {
                        if (e == mx)
                            mxB++;
                        if (e == mn)
                            mnB++;
                    }
                }
                if (mnB == 1 && mxB == 1)
                {   
                    o++;
                    break;
                }
            }

            // cout << mXN << endl;
            if (mXN == -1)
                break;

            bool mnB = 0, mxB = 0;
            for (int i = 0; i < 4; i++)
            {
                int e = t[i];
                // cout<<e<<endl;
                if (ne[i] || mne[i])
                    continue;
                if (e + mXN <= N)
                {
                    if (e == mx)
                    {
                        if (mxB)
                        {
                            // cout << "[" << i << "] mx;\n";
                            ne[i] = 1;
                            mne[i] = 1;
                            mXN += e;
                        }
                        else
                        {
                            mxB = 1;
                        }
                    }
                    else if (e == mn)
                    {
                        if (mnB)
                        {
                            // cout << "[" << i << "] mn;\n";
                            ne[i] = 1;
                            mne[i] = 1;
                            mXN += e;
                        }
                        else
                        {
                            mnB = 1;
                        }
                    }
                    else
                    {
                        // cout << "[" << i << "] else;\n";
                        ne[i] = 1;
                        mne[i] = 1;
                        mXN += e;
                    }
                }
            }
            // cout << "mXN2: " << mXN << endl;
            updatemn();
            updatemx();
            o++;
            mXN = mx + mn;
        }
    }else
    {

        int mXN = mx + mn;
        while (mXN == N)
        {
            cout << mXN << endl;
            updatemx();
            updatemn();
            o++;
            mXN = mx + mn;
        }

        while (mXN < N)
        {
            if (mx == mn)
            {
                int mnB = 0, mxB = 0;
                for (int i = 0; i < 4; i++)
                {
                    int e = t[i];

                    // cout<<e<<endl;
                    if (ne[i] || mne[i])
                        continue;
                    if (e + mXN <= N)
                    {
                        if (e == mx)
                            mxB++;
                        if (e == mn)
                            mnB++;
                    }
                }
                if (mnB == 1 && mxB == 1)
                {   
                    o++;
                    break;
                }
            }

            // cout << mXN << endl;
            if (mXN == -1)
                break;

            bool mnB = 0, mxB = 0;
            int br=2;
            for (int i = 0; i < 4; i++)
            {
                int e = t[i];
                // cout<<e<<endl;
                if (br==M)
                    break;                
                if (ne[i] || mne[i])
                    continue;
                if (e + mXN <= N)
                {
                    if (e == mx)
                    {
                        if (mxB)
                        {
                            // cout << "[" << i << "] mx;\n";
                            ne[i] = 1;
                            mne[i] = 1;
                            mXN += e;
                            br++;
                        }
                        else
                        {
                            mxB = 1;
                        }
                    }
                    else if (e == mn)
                    {
                        if (mnB)
                        {
                            // cout << "[" << i << "] mn;\n";
                            ne[i] = 1;
                            mne[i] = 1;
                            mXN += e;
                            br++;
                        }
                        else
                        {
                            mnB = 1;
                        }
                    }
                    else
                    {
                        // cout << "[" << i << "] else;\n";
                        ne[i] = 1;
                        mne[i] = 1;
                        mXN += e;
                        br++;
                    }
                }
            }
            // cout << "mXN2: " << mXN << endl;
            updatemn();
            updatemx();
            o++;
            mXN = mx + mn;
        }
    }

    cout << o << endl;
    return 0;
}
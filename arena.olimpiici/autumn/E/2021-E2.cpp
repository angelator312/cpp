#include <iostream>
#define ret(a, b, c)               \
    cout << a << endl;             \
    cout << b << " " << c << endl; \
    coutb = true;
#if 0
#define P(a) cout << a << endl
#else
#define P(a)
#endif
using namespace std;
int minSMmM(int a, int b, int c, int d)
{
    if (a > c)
    {
        return 2;
    }
    else if (a == c)
    {
        if (b >= d)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
bool isCorrectSh(int a, int b, int c, int d, int w)
{
    d += w;
    c = c + d / 10;
    d %= 10;
    if (minSMmM(a, b, c, d) == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    };
}
bool isCorrectD(int a,int b,int c,int d){

    if (a > c)
    {
        return 1;
    }
    else if (a == c)
    {
        if (b >= d)
        {
            return 1;
        }else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

}
int main()
{
    bool coutb = 0;
    int o1[4], o2[4], um[4];
    cin >> um[0] >> um[1] >> um[2] >> um[3];
    cin >> o1[0] >> o1[1] >> o1[2] >> o1[3];
    cin >> o2[0] >> o2[1] >> o2[2] >> o2[3];
    int sh1[2], d1[2], sh2[2], d2[2], shm[2], dm[2];

    if (minSMmM(o1[0], o1[1], o1[2], o1[3]) == 1)
    {
        sh1[0] = o1[0];
        sh1[1] = o1[1];
        d1[0] = o1[2];
        d1[1] = o1[3];
    }
    else
    {
        d1[0] = o1[0];
        d1[1] = o1[1];
        sh1[0] = o1[2];
        sh1[1] = o1[3];
    }

    if (minSMmM(o2[0], o2[1], o2[2], o2[3]) == 1)
    {
        sh2[0] = o2[0];
        sh2[1] = o2[1];
        d2[0] = o2[2];
        d2[1] = o2[3];
    }
    else
    {
        d2[0] = o2[0];
        d2[1] = o2[1];
        sh2[0] = o2[2];
        sh2[1] = o2[3];
    }

    if (minSMmM(um[0], um[1], um[2], um[3]) == 1)
    {
        shm[0] = um[0];
        shm[1] = um[1];
        dm[0] = um[2];
        dm[1] = um[3];
    }
    else
    {
        dm[0] = um[0];
        dm[1] = um[1];
        shm[0] = um[2];
        shm[1] = um[3];
    }
    bool alfa1 = isCorrectSh(sh1[0], sh1[1], shm[0], shm[1], 10);
    bool alfa2 = isCorrectSh(sh2[0], sh2[1], shm[0], shm[1], 10);
    alfa1 = alfa1 && isCorrectD(d1[0], d1[1], dm[0], dm[1]);
    alfa2 = alfa2 && isCorrectD(d2[0], d2[1], dm[0], dm[1]);
    string os2 = to_string(sh2[0]) + "." + to_string(sh2[1]);
    string od2 = to_string(d2[0]) + "." + to_string(d2[1]);

    if (alfa1)
    {
        string os1 = to_string(sh1[0]) + "." + to_string(sh1[1]);
        string od1 = to_string(d1[0]) + "." + to_string(d1[1]);
        if (alfa2)
        {
            if (minSMmM(sh1[0], sh1[1], sh2[0], sh2[1]) == 1)
            {
                P(alfa2);

                ret(1, os1, od1);
            }
            else
            {
                ret(2, os2, od2);
            }
        }
        else
        {
            ret(1, os1, od1);
        }
    }
    else if (alfa2)
    {
        ret(2, os2, od2);
    }
    if (!coutb)
    {
        cout << 0 << endl;
    }

    return 0;
}
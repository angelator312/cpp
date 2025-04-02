#include<bits/stdc++.h>
using namespace std;

int n, q;
vector<int> values;
vector<int> zaiavki;
int x;

inline void doing1(int &m,int &l,int &r,int &mostX)
{
    if(values[m] >= x)
    {
        mostX = m;
        r = m - 1;
    }
    else
    {
        l = m + 1;
    }
}

inline void doing2(int &m,int &l,int &r,int &mostX)
{
    if(values[m] <= x)
    {
        mostX = m;
        l = m + 1;
    }
    else
    {
        r = m - 1;
    }
}

inline void binary_search_my(int &mostX,bool flag)
{
    int l = 0, r = n - 1;
    while(l <= r)
    {
        int m = (l + r) / 2;
        if(flag)
            doing1(m,l,r,mostX);
        else doing2(m,l,r,mostX);

    }
}

inline int main2()
{
    for(int i = 0; i < q; i ++)
    {
        int x=zaiavki[i];
        int leftmost = n, rightmost = -1;
        {
            int l = 0, r = n - 1;
            while(l <= r)
            {
                int m = (l + r) / 2;
                if(values[m] >= x)
                {
                    leftmost = m;
                    r = m - 1;
                }
                else
                {
                    l = m + 1;
                }
            }
        }
        {
            int l = 0, r = n - 1;
            while(l <= r)
            {
                int m = (l + r) / 2;
                if(values[m] <= x)
                {
                    rightmost = m;
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
        }
        //cout << leftmost << " " << rightmost - leftmost + 1 << " " << n - rightmost - 1 << endl;
    }
    return 1;
}
inline int main3()
{

    for(int i = 0; i < q; i ++)
    {
        x=zaiavki[i];
        int leftmost = n, rightmost = -1;

        binary_search_my(leftmost,&doing1);
        binary_search_my(rightmost,&doing2);
        //cout << leftmost << " " << rightmost - leftmost + 1 << " " << n - rightmost - 1 << endl;
    }
    return 1;
}
int main()
{
    cin >> n >> q;
    values.resize(n);
    zaiavki.resize(q);
    for(auto &x : values)
    {
        cin >> x;
    }
    for(auto &x : zaiavki)
    {
        cin >> x;
    }
    sort(values.begin(), values.end());
    const auto start{chrono::steady_clock::now()};
    for(int i=0; i<100; ++i)
    {
        main2();
    }
    const auto finish{chrono::steady_clock::now()};
    const chrono::duration<double> elapsed_seconds{finish - start};
    cout<<elapsed_seconds.count()<<endl;
    const auto start2{chrono::steady_clock::now()};
    for(int i=0; i<100; ++i)
    {
        main3();
    }
    const auto finish2{chrono::steady_clock::now()};
    const chrono::duration<double> elapsed_seconds2{finish2 - start2};
    cout<<elapsed_seconds2.count()<<endl;

}

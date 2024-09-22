#include <bits/stdc++.h>
using namespace std;
const int N = 100000; // Най-голямото число, което ще се даде на входа
int a[N];
int main() {
  int t, n;
  cin >> t >> n;
  int nums[n];
  // multiset<int> a;
  for (int i = 0; i < n; i++) {
    int e;
    cin >> e;
    nums[i] = e;
    a[e]++;
  }
  for (auto i = 0; i < n; i++) {
    int e = nums[i];
    for (auto j = i; j < n; j++) {
      {
        // cout << *i << " " << *j << endl;
        int s = e + nums[j];
        // if(s>t)break;
        if (i == j)
          if (a[e] == 1)
            continue;

        if (a[t - s] > 0) {
          cout << e << " " << nums[j] << " " << t - s << endl;
          cout << i + 1 << " " << j + 1 << " ?" << endl;

          return 0;
        }
      }
    }
  }
  return 0;
}

/*
    Greshno

    vector<int> a[N];
    int main() {
    int t, n;
    cin >> t >> n;
    int nums[n];
    //multiset<int> a;
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        nums[i]=e;
        if(a[e][0])
            a[e][0]++;
        else
        a[e].push_back(1);
        a[e].push_back(e);
    }
    for (auto i = 0; i <n; i++) {
        int e=nums[i];
        for (auto j = i; j <n; j++) {
        {
            //cout << *i << " " << *j << endl;
            int s = e + nums[j];
            //if(s>t)break;
            if (i == j)
            if (a[e][0] == 1)
                continue;


            if (a[t - s][0] > 0) {
            cout << e << " " << nums[j] << " " << t - s << endl;
            cout << i +1<< " " << j+1 << " "<<a[t-s][1] << endl;

            return 0;
            }
        }
        }
    }
    return 0;
    }


*/
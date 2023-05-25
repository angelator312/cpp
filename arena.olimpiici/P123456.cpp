#include <iostream>
using namespace std;
struct Date {
  int dh;
  int h;
  int dm;
  int m;
  int ds;
  int s;
  string toString() {
    return to_string(dh) + to_string(h) + ":" + to_string(dm) + to_string(m) +
           ":" + to_string(ds) + to_string(s);
  };
  bool isFav() {
    int iz[10]{};
    iz[dh]++;
    iz[h]++;
    iz[dm]++;
    iz[m]++;
    iz[ds]++;
    iz[s]++;
    for (int i = 1; i <= 6; i++) {
      if (iz[i] == 0)
        return false;
    }
    return true;
  }
};
Date minDate={
    .dh=1,.h=2,.dm=3,.m=4,.ds=5,.s=6
};
Date maxDate={
    .dh=6,.h=5,.dm=4,.m=3,.ds=2,.s=1
};
bool cmp(Date &a, Date &b) {
  if (a.dh < b.dh)
    return false;
  if (a.dh > b.dh)
    return true;
  if (a.h < b.h)
    return false;
  if (a.h > b.h)
    return true;
  if (a.dm < b.dm)
    return false;
  if (a.dm > b.dm)
    return true;
  if (a.m < b.m)
    return false;
  if (a.m > b.m)
    return true;
  if (a.ds < b.ds)
    return false;
  if (a.ds > b.ds)
    return true;
  if (a.s < b.s)
    return false;
  return true;
}
bool decrease(Date &a, Date &b) {
  if (a.s > 6)
    a.s = 6;
  else
    a.s--;
  if (a.s < 0) {
    a.s = 6;
    if (a.ds > 6)
      a.ds = 5;
    else
      a.ds--;
    if (a.ds < 0) {
      a.ds = 5;
      if (a.m > 6)
        a.m = 6;
      else
        a.m--;
      if (a.m < 0) {
        a.m = 6;
        if (a.dm > 6)
          a.dm = 5;
        else
          a.dm--;
        if (a.dm < 0) {
          a.dm = 5;
          if (a.h > 6)
            a.h = 6;
          else
            a.h--;
          if (a.h < 0) {
            a.h = 6;
            if (a.dh > 6)
              a.dh = 6;
            else
              a.dh--;
            if (a.dh < 0) {
              return false;
            }
          }
        }
      }
    }
  }
  return cmp(a, b);
}
int main() {
  iostream::sync_with_stdio(0);
  cout.tie(0);cin.tie(0);
  int n, br;
  cin >> n;
  for (int i = 0; i < n; i++) {
    br = 0;
    string str;
    cin >> str;
    Date d, p;
    d.s = str[7] - '0';
    d.ds = str[6] - '0';
    d.m = str[4] - '0';
    d.dm = str[3] - '0';
    d.h = str[1] - '0';
    d.dh = str[0] - '0';
    cin >> str;
    p.s = str[7] - '0';
    p.ds = str[6] - '0';
    p.m = str[4] - '0';
    p.dm = str[3] - '0';
    p.h = str[1] - '0';
    p.dh = str[0] - '0';
    bool dM=false;
    /*if(cmp(d,maxDate)){
        d=maxDate;
        dM=true;
    }
    if(cmp(minDate,p)){
        p=minDate;
        /*if(dM){
            cout<<480<<" ";
            continue;
        }*/
    // }
    // cout << p.h << endl;
    do {
      br += d.isFav();
    } while (decrease(d, p));
    cout << br << " ";
  }
  cout << endl;
  return 0;
}
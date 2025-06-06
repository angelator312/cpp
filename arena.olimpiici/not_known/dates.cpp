#include <iostream>
using namespace std;
struct Date {
  int day;
  int month;
  int year;
};
bool nextDay(Date &startDate, Date endDate) {
  int d = startDate.day, m = startDate.month, y = startDate.year;
  d = d + 1;

  if (d == 32) {
    d = 1;
    m = m + 1;
  } else if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11)) {
    d = 1;
    m = m + 1;
  } else if (d == 30 && m == 2) {
    d = 1;
    m = m + 1;
  } else if (d == 29 && m == 2 &&
             (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0))) {
    d = 1;
    m = m + 1;
  }

  if (m == 13) {
    m = 1;
    y = y + 1;
  }
  startDate.day = d;
  startDate.month = m;
  startDate.year = y;
  // cout << " d:" << d << " m:" << m << " y:" << y << endl;
  // cout << " d:" << endDate.day << " m:" << endDate.month
  //      << " y:" << endDate.year << endl;
  if (y > endDate.year)
    return false;
  if (m > endDate.month && y==endDate.year)
    return false;
  else if (d > endDate.day && m == endDate.month && y==endDate.year)
    return false;

  return true;
}
bool fromString(string date, Date &dateS) {
  dateS.day = (date[0] - '0') * 10 + date[1] - '0';
  dateS.month = (date[2] - '0') * 10 + date[3] - '0';
  dateS.year = (date[4] - '0') * 1000 + (date[5] - '0') * 100 +
               (date[6] - '0') * 10 + date[7] - '0';
  int m = dateS.month, d = dateS.day, y = dateS.year;
  if (d < 1 || d > 31) {
    // cout<<1<<endl;
    return false;
  }
  if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11)) {
    // cout<<2<<endl;
    return false;
  }
  if (d > 29 && m == 2) {
    // cout<<3<<endl;
    return false;
  }
  if (d == 29 && m == 2 && (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0))) {
    // cout<<4<<endl;
    return false;
  }
  if (m >= 13 || m < 1) {
    // cout<<5<<endl;
    return false;
  }
  return true;
}
string toString(Date date) {
  string out = "";
  out += to_string(date.day / 10) + to_string(date.day % 10);
  out += to_string(date.month / 10) + to_string(date.month % 10);
  out += to_string(date.year / 1000) + to_string(date.year / 100 % 10) +
         to_string(date.year / 10 % 10) + to_string(date.year % 10);
  return out;
}
int main() {
  string N, M;
  cin >> N >> M;
  Date startDate, endDate, proba;
  int br = 0;
  fromString(N, startDate);
  fromString(M, endDate);
  // cout<<toString(startDate)<<endl;
  while (nextDay(startDate, endDate)) {
    string p = toString(startDate);
    // cout << p << endl;
    string r = string(p.rbegin(), p.rend());
    // cout << r << endl;
    if (fromString(r, proba))
      br++;
  }
  cout << br << endl;
  return 0;
}
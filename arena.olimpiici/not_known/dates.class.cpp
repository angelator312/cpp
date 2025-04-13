#include <iostream>
using namespace std;
struct Date;
bool operator<=(const Date &date1,const Date &endDate);
struct Date {
  int day;
  int month;
  int year;
  string toString() {
    string out = "";
    out += to_string(day / 10) + to_string(day % 10);
    out += to_string(month / 10) + to_string(month % 10);
    out += to_string(year / 1000) + to_string(year / 100 % 10) +
           to_string(year / 10 % 10) + to_string(year % 10);
    return out;
  }
  bool fromString(string date) {
    day = (date[0] - '0') * 10 + date[1] - '0';
    month = (date[2] - '0') * 10 + date[3] - '0';
    year = (date[4] - '0') * 1000 + (date[5] - '0') * 100 +
           (date[6] - '0') * 10 + date[7] - '0';
    int m = month, d = day, y = year;
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
  bool nextDay(Date endDate) {
    int d = day, m = month, y = year;
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
    day = d;
    month = m;
    year = y;
    // cout << " d:" << d << " m:" << m << " y:" << y << endl;
    // cout << " d:" << endDate.day << " m:" << endDate.month
    // //      << " y:" << endDate.year << endl;
    // if (y > endDate.year)
    //   return false;
    // if (m > endDate.month && y == endDate.year)
    //   return false;
    // else if (d > endDate.day && m == endDate.month && y == endDate.year)
    //   return false;

    return *this<=endDate;
  }
};
bool operator<=(const Date &date1,const Date &endDate) {
  int y=date1.year,m=date1.month,d=date1.day;
  if (y > endDate.year)
    return false;
  if (m > endDate.month && y == endDate.year)
    return false;
  else if (d > endDate.day && m == endDate.month && y == endDate.year)
    return false;

  return true;
}

int main() {
  string N, M;
  cin >> N >> M;
  Date startDate, endDate, proba;
  int br = 0;
  startDate.fromString(N);
  endDate.fromString(M);
  // cout<<toString(startDate)<<endl;
  while (startDate.nextDay(endDate)) {
    string p = startDate.toString();
    // cout << p << endl;
    string r = string(p.rbegin(), p.rend());
    // cout << r << endl;
    if (proba.fromString(r))
      br++;
  }
  cout << br << endl;
  return 0;
}
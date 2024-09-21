//
// Created by DELL on 24-9-20.
//
#include <iostream>
#include <string>
#include <cmath>
#include <unordered_map>

using namespace std;

using ll = long long;

#define BASE_YEAR (2024)

const unordered_map<string, int> monthMap = {
  {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4}, {"May", 5}, {"June", 6},
  {"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
};

const int daysInMonth[2][12] = {
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool isLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

ll daysFromStartOfYear(int year, int month, int day) {
  ll days = 0;
  int leap = isLeapYear(year) ? 1 : 0;
  for (int i = 0; i < month - 1; ++i) {
    days += daysInMonth[leap][i];
  }
  days += day - 1;
  return days;
}

ll inSeconds(int year, int month, int day, int hour, int minute, int second) {
  ll totalDays = 0;

  for (int y = BASE_YEAR; y < year; ++y) {
    totalDays += isLeapYear(y) ? 366 : 365;
  }

  totalDays += daysFromStartOfYear(year, month, day);

  return totalDays * 24 * 3600 + hour * 3600 + minute * 60 + second;
}

string inTimeString(ll the_seconds) {
  ll days = the_seconds / (24 * 3600);
  ll hours = (the_seconds % (24 * 3600)) / 3600;
  ll minutes = (the_seconds % 3600) / 60;
  ll seconds = the_seconds % 60;

  int year = BASE_YEAR;
  while (true) {
    int daysInYear = isLeapYear(year) ? 366 : 365;
    if (days < daysInYear) break;
    days -= daysInYear;
    year++;
  }

  int leap = isLeapYear(year) ? 1 : 0;
  int month = 1;
  while (days >= daysInMonth[leap][month - 1]) {
    days -= daysInMonth[leap][month - 1];
    month++;
  }
  ll day = days + 1;

  char buf[32];
  sprintf(buf, "%04d-%02d-%02lldT%02lld:%02lld:%02lld", year, month, day, hours, minutes, seconds);
  return buf;
}

int main() {
  int year, day, hour, minute, second;
  string monthStr;
  cin >> year >> monthStr >> day >> hour >> minute >> second;

  int month = monthMap.at(monthStr);

  ll base_bj_time = inSeconds(2024, 9, 16, 0, 0, 0);
  ll base_watch_time = inSeconds(2024, 9, 1, 22, 20, 0);

  ll curr_watch_time = inSeconds(year, month, day, hour, minute, second);
  ll watch_seconds = curr_watch_time - base_watch_time;

  ll real_seconds = floor(watch_seconds * 60.0 / 59.0);

  ll real_bj_time = base_bj_time + real_seconds;

  cout << inTimeString(real_bj_time) << endl;

  return 0;
}

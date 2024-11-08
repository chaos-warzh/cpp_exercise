//
// Created by DELL on 2024/11/8.
//
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;

  assert(!s.empty());
  if (s.size() <= k) {
    puts("0");
    return 0;
  }

  char last_one = s.at(0);
  for (int idx = 0, size = (int)s.size(); idx < size && k > 0;) {
    char cur = s.at(idx);
    if (s[idx] < last_one) {
      s.replace(idx - 1, 1, "");
      size--;
      k--;
      // todo: optimize with a better algorithm
      idx = 0;
      last_one = s.at(0);
      continue;
    } else {
      idx++;
    }
    last_one = cur;
  }

  if (k > 0) {
    s = s.substr(0, s.size() - k);
  }

  bool digit_start = false;
  for (char ch : s) {
    if (!digit_start && ch == '0') {
      continue;
    } else {
      digit_start = true;
      cout << ch;
    }
  }
  if (!digit_start) puts("0");
  return 0;
}
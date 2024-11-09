//
// Created by DELL on 2024/11/9.
//
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string numstr;
  cin >> numstr;

  string newstr;
  int idx = 0;
  if (numstr[0] == '-') {
    newstr.push_back('-');
    idx++;
  } else if (numstr[0] == '+') {
    idx++;
  }

  int leading_zero = true;
  for (; idx < numstr.size(); idx++) {
    if (isdigit(numstr[idx])) {
      if (leading_zero && numstr[idx] == '0') {
        continue;
      } else {
        leading_zero = false;
      }
      newstr.push_back(numstr[idx]);
    } else {
      break;
    }
  }

  if (leading_zero) newstr.push_back('0');
  if (newstr == "-0") puts("0");
  else {
    if (newstr[0] != '-') { // +
      if (newstr.size() > 10 || newstr.size() == 10 && newstr > "2147483647") {
        cout << "2147483647";
        return 0;
      }
    } else if (newstr.size() > 11 || newstr.size() == 11 && newstr > "-2147483648") {
      cout << "-2147483648";
      return 0;
    }
    cout << newstr;
  }

  return 0;
}
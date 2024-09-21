//
// Created by DELL on 24-9-20.
//
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<char, int> dict;
string m_str = "abcdefghijklmnopqrstuvwxyz";
unsigned int max_times = 0;

bool add_cnt(char c) {
  if (auto item = dict.find(c); item == dict.end()) {
    // no found
    dict[c] = 1;
  } else {
    dict[c] = dict[c] + 1;
  }
  if (dict[c] > max_times) {
    m_str = c;
    max_times = dict[c];
  } else if (dict[c] == max_times) {
    m_str.push_back(c);
  }
  return true;
}

int main() {
  unsigned int n;
  scanf("%d", &n);

  for (int _ = 0; _ < n; _++) {
    string s;
    cin >> s;
    if (s == "add") {
      cin >> s;
      for (char c : s) {
        add_cnt(c);
      }
    } else { // query
      sort(m_str.begin(), m_str.end());
      printf("%s\n", m_str.c_str());
    }
  }
  return 0;
}


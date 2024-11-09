//
// Created by DELL on 2024/11/8.
//
#include <iostream>
#include <vector>

using namespace std;

// state compact array:
vector<vector<bool>> been(100 + 1, vector<bool>(100 + 1, false));

void merge(vector<vector<bool>> &dp, string &s, string &t, string &r, int s_idx, int t_idx) {
  if (!been[s_idx][t_idx]) {
    been[s_idx][t_idx] = true;
  } else {
    return;
  }

  dp[s_idx][t_idx] = true;
  if (s_idx < dp.size() - 1 && s[s_idx] == r[s_idx + t_idx]) {
    merge(dp, s, t, r, s_idx + 1, t_idx);
  }

  if (t_idx < dp[0].size() - 1 && t[t_idx] == r[s_idx + t_idx]) {
    merge(dp, s, t, r, s_idx, t_idx + 1);
  }
}

int main() {
  string s, t, r;
  cin >> s >> t >> r;

  int lens = s.size();
  int lent = t.size();
  int lenr = r.size();
  if (lens + lent != lenr) { puts("False"); return 0; }

  // lens x lent
  vector<vector<bool>> dp(lens + 1, vector<bool>(lent + 1, false));

  merge(dp, s, t, r, 0, 0);

  if (dp[lens][lent]) {
    puts("True");
  } else {
    puts("False");
  }

  return 0;
}
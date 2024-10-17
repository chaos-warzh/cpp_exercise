//
// Created by DELL on 2024/10/17.
//
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

int minRem(vector<vector<int>>& intervals) {
  int n = intervals.size();
  int r = 0;
  int last_end = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (intervals[i][0] < last_end) {
      ++r;
    } else {
      last_end = intervals[i][1];
    }
  }
  return r;
}

/**
 * 3
 * 09:30-11:40
 * 08:00-11:00
 * 11:50-12:00
 */
int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>>intervals(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    char s[15];
    cin >> s;
    intervals[i][0] = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    intervals[i][1] = ((s[6] - '0') * 10 + (s[7] - '0')) * 60 + (s[9] - '0') * 10 + (s[10] - '0');
  }

  sort(intervals.begin(), intervals.end(),
                    [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; } );

  // confs
  printf("%d\n", minRem(intervals));
}
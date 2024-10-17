//
// Created by DELL on 2024/10/17.
//
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
  return a[1] < b[1];
}

int minRem(vector<vector<int>> & durings) {
  int n = durings.size();
  int r = 0;
  int last_end = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (durings[i][0] < last_end) {
      ++r;
    } else {
      last_end = durings[i][1];
    }
  }
  return r;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>>durings(n, vector<int>(2));
  for (int i = 0; i < n; i++) {
    char s[15];
    cin >> s;
    durings[i][0] = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 + (s[4] - '0');
    durings[i][1] = ((s[6] - '0') * 10 + (s[7] - '0')) * 60 + (s[9] - '0') * 10 + (s[10] - '0');
  }

  sort(durings.begin(), durings.end(), cmp);

  vector<vector<int>> conflicts(n * n + n, vector<int> (2));

  int confs = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (durings[i][1] > durings[j][0]) {
        // conflicts
        conflicts[confs][0] = i;
        conflicts[confs][1] = j;
        confs++;
      }
    }
  }

  // confs
  printf("%d\n", minRem(durings));
}
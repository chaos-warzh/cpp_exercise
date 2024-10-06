//
// Created by DELL on 2024/10/7.
//

#include <iostream>
#include <climits>
#include <stack>

#define min(a, b) ((a < b) ? a : b)

using namespace std;

int n;
int an[(int)(10e6 + 5)];
int left_min[(int)(10e6 + 5)];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &an[i]);
  }

  left_min[0] = INT_MAX;
  for (int i = 1; i < n; i++) {
    left_min[i] = min(left_min[i - 1], an[i - 1]);
  }

  stack<int> s;

  for (int i = n - 1; i >= 0; i--) {
    // filter out useless nums
    while (!s.empty() && s.top() <= left_min[i]) {
      s.pop();
    }

    if (!s.empty()) {
      int right = s.top();
      if (left_min[i] < right && right < an[i]) {
        puts("True");
        return 0;
      }
    }

    s.push(an[i]);
  }

  puts("False");
  return 0;
}
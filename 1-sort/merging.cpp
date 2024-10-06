//
// Created by DELL on 2024/10/6.
//

#include<iostream>

using namespace std;

#define MAX ((int)(10e6 + 5))

int m, n;
int q1[MAX], q2[MAX];

int main() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++) {
    scanf("%d", &q1[i]);
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &q2[i]);
  }

  int i1 = m - 1, i2 = n - 1;
  while (i1 >= 0 && i2 >= 0) {
    if (q1[i1] > q2[i2]) {
      cout << q1[i1];
      i1--;
    } else {
      cout << q2[i2];
      i2--;
    }
  }

  while (i1 >= 0) {
    cout << q1[i1];
    i1--;
  }

  while (i2 >= 0) {
    cout << q2[i2];
    i2--;
  }
  return 0;
}
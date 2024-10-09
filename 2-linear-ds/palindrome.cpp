//
// Created by DELL on 2024/10/9.
//
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
#define N_MAX 12
#define N2_MAX 34

int main() {
  int W;
  scanf("%d", &W);
  char s1[N_MAX];
  char s2[N_MAX];
  char ss1[N2_MAX];
  char ss2[N2_MAX];

  bool is_pali = false;
  bool is_pali2 = false;

  for (int i = W; i < INT_MAX; i++) {
    itoa(i, s1, 10);
    itoa(i, s2, 10);
    strrev(s1);
    if (strcmp(s1, s2) == 0) {
      is_pali = true;
    }
    if (!is_pali) continue;

    itoa(i, ss1, 2);
    itoa(i, ss2, 2);
    strrev(ss1);
    if (strcmp(ss1, ss2) == 0) {
      is_pali2 = true;
    }
    if (is_pali2) {
      cout << i;
      return 0;
    }
    is_pali = false;
  }

  return 0;
}
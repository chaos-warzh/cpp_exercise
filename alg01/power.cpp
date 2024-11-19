//
// Created by DELL on 2024/11/19.
//
#include <iostream>

using namespace std;

#define MOD (int)(1e9 + 7)

int main() {
  long long a, k;
  cin >> a >> k;

  long long ans = 1;

  while (k) {
    if (k & 1) {
      ans = ans * a % MOD;
    }
    a = a * a % MOD;
    k >>= 1;
  }
  cout << ans;
  return 0;
}
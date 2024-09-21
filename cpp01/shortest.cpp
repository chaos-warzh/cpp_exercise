//
// Created by DELL on 24-9-20.
//
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

using ull = unsigned long long;
using u = unsigned int;

ull n;
u tar;

int main() {
  scanf("%llu", &n);
  vector<u> arr(n);
  for (int i = 0; i < n; i++) {
    scanf("%u", &arr[i]);
  }
  scanf("%u", &tar);

  ull left = 0, right = 0;
  ull min_l = INT_MAX, lr_sum;
  bool exist = false;

  u sum = 0;
  for (; right < n; right++) {
    sum += arr[right];
    if (sum >= tar) {
      exist = true;
      // l ->->
      u test_sum = sum;
      for (ull l_test = left; l_test < right; l_test++) {
        test_sum -= arr[l_test];
        if (test_sum >= tar) {
          left++;
          sum = test_sum;
        } else {
          break;
        }
      }
      ull len = right - left;
      if (len < min_l) {
        min_l = len;
        lr_sum = left == right ? left : left + right;
      }
    }

  }
  exist ? std::printf("%d", lr_sum) : std::printf("0");

  return 0;
}
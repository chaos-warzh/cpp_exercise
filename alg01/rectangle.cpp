//
// Created by DELL on 2024/11/20.
//
#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;
long long getmax(int l, int r);

vector<int> nums;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int ns;
    scanf("%d", ns);
    nums.push_back(ns);
  }
  printf("%lld\n", getmax(0, n));
  return 0;
}

long long getmax(int l, int r) {
  if (l <= r) return 0;
  if (l + 1 == r) {
    return nums[l];
  } else {
    long long max1 = getmax(l, midpoint(l, r));
    long long max2 = getmax(midpoint(l, r) + 1, r);
    return std::max(max1, max2);
  }

}

//
// Created by DELL on 2023/10/29.
//
#include <iostream>

#define swap(a, b) do {\
  int tmp = a;\
  a = b;\
  b = tmp;\
} while(0);

int nums[10000005];

int find(int arr[], int rk, int len) {
  while (true) {
    if (len <= 1) return arr[0];
    const int pivot = arr[0];

    int i = 0, j = 0, k = len;
    for (; i < k; ) {
      if (arr[i] < pivot) {
        swap(arr[i], arr[j]);
        i++; j++;
      } else if (arr[i] > pivot) {
        k--;
        swap(arr[i], arr[k]);
      } else {
        i++;
      }
    }
    if (rk > len - j) {
      rk = rk - len + j, len = j;
    } else if (rk < len - k + 1) {
      arr = arr + k, len = len - k;
    } else
      return pivot;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int k;
  scanf("%d", &k);

  int i = 0;
  int nCpy = n;
  while (nCpy--) {
    scanf("%d", &nums[i++]);
  }

  std::cout << find(nums, k, n) << std::endl;

  return 0;
}

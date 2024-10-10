//
// Created by DELL on 2024/10/10.
//
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

#define swap(a, b) do { \
  a ^= b ^= a ^= b;     \
} while(0)

class Solution {
  public:
  void sortColors(vector<int>& nums) {
    int head = -1;
    int tail = (int)nums.size() - 1;

    for (int i = 0; i <= tail; i++) {
      if (nums[i] == 0 && head != -1) {
        swap(nums[i], nums[head]);
        head++;
      } else if (nums[i] != 0 && head == -1) {
        head = i;
      }
      if (nums[i] == 2) {
        swap(nums[i], nums[tail]);
        tail--;
        i--;
      }
    }
  }
};

int main() {
  auto solution(std::make_unique<Solution>());
  vector<int> nums = {2, 0, 1};
  solution->sortColors(nums);
  for (int i : nums) {
    cout << i << endl;
  }
}
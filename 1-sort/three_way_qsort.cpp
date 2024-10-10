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
    int head = 0, tail = nums.size();
    for (int i = head; i < tail; i++) {
      if (nums[i] == 0) {
        swap(nums[i], nums[head]);
        head++;
      } else if (nums[i] == 2) {
        swap(nums[i], nums[tail]);
        tail--;
      } else {
        continue;
      }
      i--;
    }
  }
};

int main() {
  auto solution(std::make_unique<Solution>());
  int vec[5] = {0, 1, 2, 1, 0};
  vector<int> nums(vec, vec + 5);
  solution->sortColors(nums);
  for (int i : nums) {
    cout << i << endl;
  }
}
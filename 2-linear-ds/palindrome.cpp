//
// Created by DELL on 2024/10/9.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isBinaryPalindrome(int num) {
  int original = num;
  int reversed = 0;
  while (num > 0) {
    reversed = (reversed << 1) | (num & 1);
    num >>= 1;
  }
  return original == reversed;
}

// 生成回文数
// 不是遍历所有数然后判断, 而是遍历数然后生成, 这样复杂度是 √n
void generatePalindromes(vector<int>& palindromes) {
  for (int i = 1; i < 10000; i++) {
    string s = to_string(i);
    string rev = string(s.rbegin(), s.rend());
    long palindrome = stol(s + rev);
    if (palindrome <= INT_MAX)
      palindromes.push_back((int) palindrome);
  }

  for (int i = 1; i < 90000; i++) {
    string s = to_string(i);
    string rev = string(s.rbegin(), s.rend());
    long palindrome = stol(s + rev.substr(1));
    if (palindrome <= INT_MAX){
      palindromes.push_back((int)palindrome);
    }
  }
  sort(palindromes.begin(), palindromes.end()); // 排序
  palindromes.erase(unique(palindromes.begin(), palindromes.end()), palindromes.end()); // 去重
}

int main() {
  int W;
  cin >> W;

  vector<int> palindromes;
  generatePalindromes(palindromes);

  for (int pal : palindromes) {
    if (pal > W && isBinaryPalindrome(pal)) {
      cout << pal;
      return 0;
    }
  }

  return 0;
}
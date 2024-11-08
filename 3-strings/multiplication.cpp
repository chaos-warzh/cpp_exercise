//
// Created by DELL on 2024/11/8.
//
#include <cstdio>
#include <vector>

using namespace std;

int n, pivot;

vector<int> num1, num2;

vector<int> result;

void multiply() {
  unsigned long long len1 = num1.size();
  unsigned long long len2 = num2.size();
  result.resize(len1 + len2);
  fill(result.begin(), result.end(), 0);

  for (int i = 0; i < len1; ++i) {
    for (int j = 0; j < len2; ++j) {
      result[i + j] += num1[len1 - 1 - i] * num2[len2 - 1 - j];

      if (result[i + j] >= 10) {
        result[i + j + 1] += result[i + j] / 10;
        result[i + j] %= 10;
      }
    }
  }

  while (result.size() > 1 && result.back() == 0) {
    result.pop_back();
  }
}

int main() {
  scanf("%d%d", &n, &pivot);

  short temp;
  while (n--) {
    scanf("%hd", &temp);
    if (temp < pivot) {
      num1.push_back(temp);
    } else { // temp >= pivot
      num2.push_back(temp);
    }
  }

  if (num1.empty() || num2.empty()) { puts("0"); return 0; }

  multiply();

  for (auto iter = result.rbegin(); iter < result.rend(); iter++) {
    printf("%d", *iter);
  }
  return 0;
}
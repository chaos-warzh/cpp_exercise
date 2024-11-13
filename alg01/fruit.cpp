//
// Created by DELL on 2024/11/9.
//

#include <cstdio>
#include <queue>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  priority_queue<int, vector<int>, greater<>> piles; // min heap

  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    piles.push(tmp);
  }

  int count = 0;

  // merge
  while (true) {
    int min1 = piles.top();
    piles.pop();
    if (piles.empty()) break;

    int min2 = piles.top();
    piles.pop();

    count += min1 + min2;
    piles.push(min1 + min2);
  }

  printf("%d\n", count);

  return 0;
}

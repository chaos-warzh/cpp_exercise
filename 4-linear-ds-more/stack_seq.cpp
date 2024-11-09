//
// Created by DELL on 2024/11/9.
//

#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main() {
  stack<int> stck;

  int len;
  scanf("%d", &len);
  vector<int> sq;

  for (int i = 1, tmp; i <= len; i++) {
    scanf("%d", &tmp);
    sq.push_back(tmp);
  }


  for (int idx = 0, iter = 0; iter < len; iter++){
    int top = iter + 1;
    stck.push(top);

    while (sq[idx] == top) {
      stck.pop();
      idx++;
      if (stck.empty()) break;
      top = stck.top();
    }

  }

  puts(stck.empty() ? "True" : "False");
  return 0;
}
//
// Created by DELL on 2024/11/8.
//
#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;
vector<vector<int>> vals(32);
int layer = 0;
int last_idx;

int value(const vector<int> &v, int start, int end) {
  if (start + 1 == end) return 1;
  for (int i = start; i <= end; i++) {
    if (v[i] == 1) { // (
      layer++;
      last_idx = i;
    } else { // )
      layer--;
      if (last_idx + 1 == i) { // value, 1
        vals[layer].push_back(1);
      } else { // value x2
        int sum = accumulate(vals[layer + 1].begin(), vals[layer + 1].end(), 0);
        vals[layer + 1].clear();
        vals[layer].push_back(sum * 2);
      }
    }
  }
  return accumulate(vals[0].begin(), vals[0].end(), 0);
}

int main() {
  int len;
  scanf("%d ", &len);

  vector<int> v(len);

  char ch;
  for (int i = 0; i < len; i++) {
    ch = getchar();
    if (ch == '(') {
      v[i] = 1;
    } else {
      v[i] = -1;
    }
  }

  printf("%d\n", value(v, 0, len - 1));

  return 0;
}

//
// Created by DELL on 2024/11/9.
//
#include <cstdio>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

int total_num, k, start;

list<int> circle;
vector<int> seq;

void gen_seq(int skip) {
  // circle
  auto sz = (int)circle.size();

  auto cur = circle.begin();

  while (sz > 0) {
    for (int i = 0; i < skip - 1; i++) {
      cur++;
      if (cur == circle.end()) {
        cur = circle.begin();
      }
    }

    seq.push_back(*cur);
    cur = circle.erase(cur);
    if (cur == circle.end()) {
      cur = circle.begin();
    }
    sz--;

  }
}

int main() {
  scanf("%d%d%d", &total_num, &k, &start);

  vector<int> rev_mapping(total_num + 1);

  start--; // start from 0

  int rev_start = start;
  for (int _ = 0; _ < total_num; _++) {
    circle.push_back(start);
    rev_mapping[start] = rev_start;
    start = (start + 1) % total_num;
    rev_start = (rev_start + total_num - 1) % total_num;
  }

  gen_seq(k);

  for_each(seq.begin(), seq.end(),[](int i){ printf("%d ", i + 1); });
  puts("");

  for_each(seq.begin(), seq.end(), [&rev_mapping](int i){ printf("%d ", rev_mapping[i] + 1); });

  return 0;
}
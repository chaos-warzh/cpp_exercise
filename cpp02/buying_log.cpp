//
// Created by DELL on 2024/10/12.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Record {
  char op[8];
  int id;
  int money;
};

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  auto *records = (Record *) malloc(m * sizeof(Record));

  for (int i = 0; i < m; ++i) {
    scanf("%s %d %d", records[i].op, &records[i].id, &records[i].money);
  }

  // reversed traverse
  long long profit = 0;
  auto *maxPrices = (int *) malloc((n + 1) * sizeof(int));
  memset(maxPrices, -1, (n + 1) * sizeof(int)); // 初始化为0

  for (int i = m - 1; i >= 0; i--) {
    int id = records[i].id;
    int money = records[i].money;

    if (money > maxPrices[id])
      maxPrices[id] = money;

    if (records[i].op[0] == 'b')  // buy
      profit += maxPrices[id] - money;
  }

  printf("%lld\n", profit);

  free(records);
  free(maxPrices);

  return 0;
}

//
// Created by DELL on 2024/10/11.
//
#include <cstdio>

using namespace std;

int row, col;

int find(int x, int pre[]) {
  int r = x;
  while (pre[r] != r) {
    r = pre[r];
  }
  // path compression
  int i = x;
  int j;
  while (i != r) {
    j = pre[i];
    pre[i] = r;
    i = j;
  }
  return r;
}

void u(int x, int y, int pre[]) {
  int fx = find(x, pre);
  int fy = find(y, pre);
  if (fx != fy) {
    pre[fx] = fy;
  }
}

int main() {
  scanf("%d%d", &row, &col);


  int pre[row * col];
  int table[row][col];
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      scanf("%d", &table[i][j]);
    }
  }

  for (int i = 0; i < row * col; i++) {
    pre[i] = i;
  }

  for (int i = 0; i < row * col; i++) {
    int x = i / col;
    int y = i % col;
    int val = table[x][y];
    if (x - 1 >= 0 && val == table[x - 1][y])  u(i, i - col, pre);
    if (x + 1 < row && val == table[x + 1][y])  u(i, i + col, pre);
    if (y - 1 >= 0 && val == table[x][y - 1]) u(i, i - 1, pre);
    if (y + 1 < col && val == table[x][y + 1]) u(i, i + 1, pre);
  }

  
  int x, y;
  scanf("%d%d", &x, &y);
  int target = (x - 1) * col + y - 1;
  for (int j = 0; j < col; j++) {
    int row_no = row - 1;
    for (int i = row - 1; i >= 0; i--) {
      int cur = i * col + j;
      if (find(cur, pre) == find(target, pre)) {
        continue;
      } else {
        table[row_no][j] = table[i][j];
        row_no--;
      }
    }
    while (row_no >= 0) {
      table[row_no][j] = 0;
      row_no--;
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      printf("%d ", table[i][j]);
    }
    puts("");
  }

  return 0;
}
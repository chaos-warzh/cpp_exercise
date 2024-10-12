//
// Created by DELL on 2024/10/12.
//
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

const int MAX_M = 100;
const int MAX_N = 6;
const int INF = INT_MAX;

int dist[MAX_M][MAX_M]; // distant matrix
int n;                // order nums
int m;               // spots nums
int rest[MAX_N];        // restaurant
int cust[MAX_N];        // customer

void floyd() {
  for (int k = 0; k < m; k++)
    for (int i = 0; i < m; i++)
      for (int j = 0; j < m; j++)
        if (dist[i][k] != INF && dist[k][j] != INF)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

// dfs:
// mask_fetch: orders
// last: current spot
int dfs(int mask_fetch, int mask_send, int last) {
  // all FINISHED
  if (mask_fetch == (1 << n) - 1 && mask_send == (1 << n) - 1) {
    return 0;
  }

  int ans = INF;

  for (int i = 0; i < n; i++) {
    // fetch takeout
    if (!(mask_fetch & (1 << i))) { // 0 for the i-th lowest bit
      int time = dist[last][rest[i]];
      int new_mask_fetch = mask_fetch | (1 << i);
      ans = min(ans, time + dfs(new_mask_fetch, mask_send, rest[i]));
    } else if ((mask_fetch & (1 << i)) && !(mask_send & (1 << i))) { // send takeout
      // 1 - fetch ; 0 - send
      int time = dist[last][cust[i]];
      int new_mask_send = mask_send | (1 << i);
      ans = min(ans, time + dfs(mask_fetch, new_mask_send, cust[i]));
    }
  }

  return ans;
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &dist[i][j]);
      if (dist[i][j] == -1) {
        dist[i][j] = INF;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &rest[i], &cust[i]);
    rest[i]--;
    cust[i]--;
  }

  floyd();

  int result = dfs(0, 0, 0);

  printf("%d", result);
  return 0;
}
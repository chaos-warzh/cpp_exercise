//
// Created by DELL on 2024/11/15.
//
#include <cstdio>

using namespace std;

#define MOD ((int)(1e9 + 7))

typedef long long ll;

ll res[][5] = {{1, 0, 0, 0, 0},
               {0, 1, 0, 0 , 0},
               {0, 0, 1, 0, 0},
               {0, 0, 0, 1, 0},
               {0, 0, 0, 0, 1},
               };
ll tmp[5][5];
ll matrix[5][5];

int n, p;

void matrix_mul(const ll (&a)[5][5], const ll (&b)[5][5], ll (*res_p)[5][5]) {

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ll sum = 0;
      for (int k = 0; k < n; k++) {
        sum += (a[i][k] * b[k][j]) % MOD;
        sum %= MOD;
      }
      (*res_p)[i][j] = sum;
    }
  }
}

int main() {

  scanf("%d%d", &n, &p);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%lld", &matrix[i][j]);
    }
  }

  ll (*res_ptr)[5][5] = &res;
  ll (*other_ptr)[5][5] = &tmp;
  ll (*matrix_ptr)[5][5] = &matrix;


  while (p) {
    if (p & 1) {
      matrix_mul(*res_ptr, *matrix_ptr, other_ptr);
      ll (*tmp_res_ptr)[5][5] = res_ptr;
      res_ptr = other_ptr;
      other_ptr = tmp_res_ptr;
    }
    matrix_mul(*matrix_ptr, *matrix_ptr, other_ptr);
    ll (*tmp_matrix_ptr)[5][5] = matrix_ptr;
    matrix_ptr = other_ptr;
    other_ptr = tmp_matrix_ptr;
    p >>= 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%lld ", (*res_ptr)[i][j]);
    }
    puts("");
  }
  return 0;
}
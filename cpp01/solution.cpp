//
// Created by DELL on 24-9-20.
//

#include <cmath>
#include <cstdio>
#include <cassert>

#define mid(x, y) ((x + y) / 2)

using namespace std;

double a, b;

#define eval(x) \
(exp(x) - a * x - b > 0)

int main() {
  scanf("%lf %lf", &a, &b);

  double l = 0, r = 10;
  int signl = eval(l) ? 1 : -1;
  int signr = eval(r) ? 1 : -1;
  assert(signl * signr < 0);

  while (r - l >= 0.000001) {
    double m = mid(l, r);
    int signm = eval(m) ? 1 : -1;
    if (signl * signm > 0) {
      l = m;
    } else if (signr * signm > 0) {
      r = m;
    } else {
      assert(false);
    }
  }

  printf("%.6f", mid(l, r));

  return 0;
}
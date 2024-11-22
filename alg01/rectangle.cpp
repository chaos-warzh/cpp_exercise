//
// Created by DELL on 2024/11/20.
//
#include <cstdio>
#include <vector>
#include <numeric>
#include <stack>

using namespace std;
void getmax();

vector<int> heights;
stack<int> mono_stack;

#define MAX(a, b) ((a > b) ? a : b)
int max_area = -1;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int ns;
    scanf("%d", &ns);
    heights.push_back(ns);
  }
  getmax();
  printf("%d\n", max_area);
  return 0;
}

void getmax() {
  for (int i = 0; i < mono_stack.size(); i++) {
    int value = heights[i];
  }
}

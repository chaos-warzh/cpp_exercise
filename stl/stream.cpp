//
// Created by DELL on 2024/11/6.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  vector<int> v;
  int len;
  cin >> len;
  while (len--) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  cout << "max: " << *max_element(v.begin(), v.end()) << endl;
  cout << "max: " << *std::ranges::max_element(v) << endl;

  cout << "sum: " << accumulate(v.begin(), v.end(), 0) << endl;

  sort(v.begin(), v.end());
  std::ranges::sort(v);

  std::ranges::for_each(v, [](auto x) {
    cout << x << ' '; }
  );

  return 0;
}
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
  cout << "max: " << *ranges::max_element(v) << endl;

  cout << "sum: " << accumulate(v.begin(), v.end(), 0) << endl;

//  sort(v.begin(), v.end());
  ranges::sort(v);

  ranges::for_each(v, [](auto x) {
    cout << x << ' '; }
  );
  puts("");

  // erase_if (like removeIf in Java)
  erase_if(v, [](int x){ return x % 2 == 0; } );

  ranges::for_each(v, [](auto x) {
    cout << x << ' '; }
  );
  return 0;
}
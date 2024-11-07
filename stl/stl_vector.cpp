//
// Created by DELL on 2024/11/7.
//

#include <iostream>
#include <ranges>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> v = {2, 8, 11, 3, 15, 7};

  for (auto iter = v.rbegin(); iter != v.rend(); iter++) {
    cout << *iter << ' ';
  }
  puts("");

  for (int & iter : std::ranges::reverse_view(v)) {
    cout << iter << ' ';
  }
  puts("");

  cout << v.front() << ' ' << v.back() << endl;

//  sort(v.begin(), v.end(), [](int a, int b) {return a > b;});
  ranges::sort(v, [](int a, int b) { return a < b; } );

  ranges::for_each(v, [](int a){ cout << a << ' '; });
  puts("");

  v.pop_back();
  v.insert(v.begin(), 6, 114);


  ranges::for_each(v, [](int a){ cout << a << ' '; });
  puts("");

  v.erase(v.end() - 1, v.end());
  v.clear();
  cout << v.size();

  return 0;
}
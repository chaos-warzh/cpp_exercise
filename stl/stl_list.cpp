//
// Created by DELL on 2024/11/8.
//

#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  list<int> l = {1, 1, 4, 5, 1, 3}; // double linked list

  list<int> l1 = {1, 4, 3};

  l.assign(l1.begin(), l1.end());
  ranges::for_each(l, [](int i){ cout << i << ' '; });
  puts("");

  l.reverse();
  ranges::for_each(l, [](int i){ cout << i << ' '; });
  puts("");

  l.sort();
  ranges::for_each(l, [](int i){ cout << i << ' '; });
  puts("");

  auto result = ranges::find_if(l, [](int i){ return i % 2 == 0; });
  cout << *result << endl;

  long long even_count = ranges::count_if(l, [](int i){ return i % 2 == 0; });
  cout << even_count << endl;
  return 0;
}
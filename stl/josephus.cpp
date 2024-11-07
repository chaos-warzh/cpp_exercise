//
// Created by DELL on 2024/11/8.
//

#include <iostream>
#include <list>
using namespace std;

int main() {
  int num, n; // num: number to kill, n: total count of monkeys
  cin >> n >> num;

  list<int> circle;

  for (int i = 1; i <= n; i++) {
    circle.push_back(i);
  }

  list<int>::iterator current;
  current = circle.begin();

  while (circle.size() > 1) {
    for (int count = 1; count < num; count++) { // saying number for num - 1 times
      current++;
      if (current == circle.end()) {
        current = circle.begin();
      }
    }
    current = circle.erase(current);
    if (current == circle.end()) current = circle.begin();
  }

  cout << *circle.begin() << endl;
  return 0;
}
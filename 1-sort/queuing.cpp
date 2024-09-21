//
// Created by DELL on 2024/9/21.
//


#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int m, n;


int main() {
  scanf("%d%d", &m, &n);
  vector<int> persons(100);
  int index = 0; // of persons
  for (int i = 0; i < m; i++) {
    while (true) {
      char ch;
      scanf(" %c ", &ch);
      if (ch != '#') {
        persons[index] = ch - 48;
        index++;
      } else {
        break;
      }
    }
    //
    persons.erase(persons.end() - n + 1);
    index--;
    for (const auto &item : persons) {
      printf("%d ", item);
    }
    puts("#");
  }
  return 0;
}

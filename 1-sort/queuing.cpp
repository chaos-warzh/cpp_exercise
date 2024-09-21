//
// Created by DELL on 2024/9/21.
//

// #2
// very important! you must recite it !!!
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int m, n;

int main() {
  scanf("%d%d ", &m, &n);
  vector<int> persons(100 * 100 + 95);
  int index = 0;

  for (int i = 0; i < m; i++) {
    /* how to handle this kind of input -- A standard way */
    string line;
    getline(std::cin, line);

    int num;
    std::stringstream ss(line);

    while (ss >> num) {
      persons[index] = num;
      index++;
      ss >> std::ws;
      if (ss.peek() == '#') { // or EOF
        break;
      }
    }

    persons.erase(persons.begin() + index - n);
    index--;
    for (int i = 0; i < index; i++) {
      const auto &item = persons[i];
      printf("%d ", item);
    }
    puts("#");
  }
  return 0;
}

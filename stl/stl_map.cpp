//
// Created by DELL on 2024/11/8.
//
#include <iostream>
#include <map>
using namespace std;

int main() {
  map<int, string> students;
  students.insert(make_pair(1001, "Alice"));
  students.try_emplace(1002, "Bob");
  students[1003] = "Charlie";

  for (const auto& st: students) {
    cout << "ID: " << st.first << ", Name: " << st.second << endl;
  }

  int searchID = 1002;
  auto it = students.find(searchID);
  if (it != students.end()) {
    cout << "found: " << it->second << endl;
  } else {
    cout << "not found.\n";
  }

  students[1001] = "Alicia";
  for (const auto& entry : students) {
    cout << "ID: " << entry.first << ", Name: " << entry.second << endl;
  }

  students.erase(1003);
  for (const auto& entry : students) {
    cout << "ID: " << entry.first << ", Name: " << entry.second << endl;
  }

  int countID = 1002;
  unsigned long long count = students.count(countID);
  cout << "ID " << countID << " count: " << count << endl;

  return 0;
}
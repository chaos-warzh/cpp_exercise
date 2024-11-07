//
// Created by DELL on 2024/11/8.
//
#include <bits/stdc++.h>

using namespace std;

enum Sex {
  MALE, FEMALE,
};

enum Major {
  CS, SE, AI, EE,
};

class Student {
  private:
    int no;
    string name;
    Sex sex;
    Major major;

  public:
    Student(int i, const string s, Sex sex, Major major): no(i), name(s), sex(sex), major(major) {}

    int get_no() { return no; }
    string get_name() { return name; }
    Sex get_sex() { return sex; }
    Major get_major() { return major; }
    void display() { cout << "no." << no << " " << name << ", " << (sex == MALE ? "M" : "F") << " Major" << major << endl; }
};

int main() {
  vector<Student> students;
  int n;
  cin >> n;
  while (n--) {
    int no;
    string name;
    int sex;
    int major;
    cin >> no >> name >> sex >> major;
    Student st(no, name, (Sex)sex, (Major)major);
    students.push_back(st);
  }

  ranges::sort(students, [](Student &s1, Student &s2){ return s1.get_no() < s2.get_no(); });
  ranges::for_each(students, [](Student &s){ s.display(); });
  cout << ranges::count_if(students, [](Student &s){ return s.get_major() == SE; });
}
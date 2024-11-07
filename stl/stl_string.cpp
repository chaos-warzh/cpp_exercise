//
// Created by DELL on 2024/11/7.
//

#include <iostream>
using namespace std;

int main() {
  string s = "hello world";
  try {
    char ch = s.at(100);
    cout << ch << endl;
  } catch (out_of_range &e) {
    cout << e.what() << endl;
  }

  const char *cstr = s.c_str();
  string str(cstr);

  int a = 114514;
  str = to_string(a);
  cout << str << endl;

  a = stoi(str); // stoul stoull; stof stod stold
  cout << a << endl;

  // basic operations
  char ch = str[0];
  ch = str.at(0);
  str = str + "+";
  str += "1919810";
  cout << str << endl;

  unsigned long long idx = str.find("11", 0); // rfind
  if (idx != -1) cout << idx << endl;

  str = str.replace( 6, 1, "!=");
  cout << str << endl;

  str.erase(str.end() - 1, str.end());
  cout << str << endl;

  str.insert(0, "comp: ");
  cout << str << endl;

  cout << str.compare("1234") << endl;

  cout << str.substr(6, 6);

  return 0;
}
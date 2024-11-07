//
// Created by DELL on 2024/11/7.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Stack {
  public:
  bool 	push( const string& );
  bool	pop( string & );
  bool 	peek( string & ) const;

  [[nodiscard]] bool 	empty() const;
  [[nodiscard]] bool 	full() const;

  [[nodiscard]] unsigned long long
  size() const { return _stack.size(); } // implemented in class, viewed as inlined

  private:
  vector<string> _stack;
};

inline bool Stack::empty() const {
  return _stack.empty();
}

bool Stack::pop(std::string &elem) {
  if ( empty() ) return false;

  elem = _stack.back();
  _stack.pop_back();
  return true;
}

inline bool Stack::full() const {
  return _stack.size() == _stack.max_size();
}

bool Stack::peek(std::string &elem) const {
  if ( empty() ) return false;

  elem = _stack.back();
  return true;
}

bool Stack::push(const std::string &elem) {
  if ( full() ) return false;

  _stack.push_back( elem );
  return true;
}

int main() {
  Stack s;
  s.push("aaa");
  string str;
  s.peek(str);
  cout << str << endl;

  return 0;
}

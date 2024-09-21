#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

string password;
int k;
int dash_num;

bool process() {
  std::transform(password.begin(), password.end(), password.begin(), ::toupper);
  dash_num = (password.size() + k -1) / k - 1;
  unsigned long long kth_group_nums = password.size() - dash_num * k;
  if (kth_group_nums <= 0 || kth_group_nums > k) { return false; }
  if (kth_group_nums != k && k > dash_num + 1) { return false; }

  int group_i = 1; int cur_index = 0;
  for (; group_i <= dash_num + 1; group_i++) {
    if (group_i != k) {
      bool hasN = false;
      bool hasCh = false;
      for (int i = 0; i < k; i++, cur_index++) {
        if (isdigit(password[cur_index])) {
          hasN = true;
        } else { // ch
          hasCh = true;
        }
      }
      if (!hasCh || !hasN) {
        return false;
      }

    } else { // group_i == k
      for (int i = 0; i < kth_group_nums; i++, cur_index++) {

      }
    }
    password.insert(cur_index, "-");
    cur_index++;
  }
  password = password.substr(0, password.size() - 1);
  return true;
}

int main() {
  cin >> password;
  scanf("%d", &k);

  int old_len = password.size();
  password
  .erase(std::remove(password.begin(), password.end(), '-'), password.end());
  int new_len = password.size();

  dash_num = old_len - new_len;

  bool success = process();
  if (!success) {
    puts("INVALID");
    return 0;
  } else { // success
    cout << password;
    return 0;
  }

  return 0;
}
//
// Created by DELL on 2024/11/9.
//
#include <iostream>
#include <array>

using namespace std;

const array<string, 20> ONES = {
  "", "one ", "two ", "three ", "four ", "five ",
  "six ", "seven ", "eight ", "nine ", "ten ", "eleven ",
  "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ",
  "seventeen ", "eighteen ", "nineteen "};

const array<string, 10> TENS = {
  "00", "10", "twenty", "thirty", "forty", "fifty",
  "sixty", "seventy", "eighty", "ninety"
};

typedef long long ll;

int main() {
  ll num;
  scanf("%lld", &num);

  if (num == 0) {
    puts("zero");
    return 0;
  } else if (num < 0) {
    printf("minus ");
    num = -num;
  }
  // num: [1, 2,147,483,648]

  // billion:
  ll billions = num / ((ll)(1e9));
  num = num % ((ll)(1e9));
  if (billions > 0) {
    cout << ONES[billions] << "billion ";
  }

  // million, thousand, one:
  ll nums[3] = {(ll)(1e6), (ll)(1e3), 1};
  string strs[3] = {"million ", "thousand ", ""};

  for (int i = 0; i < 3; i++) {
    ll millions = num / nums[i];
    num = num % nums[i];
    if (millions > 0) {
      ll hund = millions / 100;
      ll rests = millions % 100;
      if (hund > 0) {
        cout << ONES[hund] << "hundred ";
      }
      if (rests > 0) {
        if (hund > 0) cout << "and ";
        if (rests < 20) {
          cout << ONES[rests];
        } else {
          cout << TENS[rests / 10];
          printf((rests % 10 != 0) ? "-" : " ");
          cout << ONES[rests % 10];
        }
      }

      cout << strs[i];
    }
  }


  return 0;
}
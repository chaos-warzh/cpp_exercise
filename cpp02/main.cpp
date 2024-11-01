// 不要修改Main.cpp
#include "ArrayList.h"
#include <cassert>
#include <functional>
#include <iostream>

// === TEST_CASES ===
void TEST_1();
void TEST_2();
void TEST_3();
void TEST_4();
void TEST_5();
void TEST_6();
void TEST_7();
void TEST_8();
void TEST_9();
void TEST_10();

#define REGISTER_TEST_CASE(name) {#name, name}

int main() {
  std::unordered_map<std::string, std::function<void()>>
      test_functions_by_name = {
          REGISTER_TEST_CASE(TEST_1), REGISTER_TEST_CASE(TEST_2),
          REGISTER_TEST_CASE(TEST_3), REGISTER_TEST_CASE(TEST_4),
          REGISTER_TEST_CASE(TEST_5), REGISTER_TEST_CASE(TEST_6),
          REGISTER_TEST_CASE(TEST_7), REGISTER_TEST_CASE(TEST_8),
          REGISTER_TEST_CASE(TEST_9), REGISTER_TEST_CASE(TEST_10),
      };

  std::string test_case_name;
  std::cin >> test_case_name;
  auto it = test_functions_by_name.find(test_case_name);
  assert(it != test_functions_by_name.end());
  auto fn = it->second;
  fn();
  return 0;
}

void TEST_1() { // 测试add函数
  ArrayList<int> a;
  a.add(1);
  a.add(2);
  a.add(3);

  assert(a.getSize() == 3);
  assert(a.getCapacity() == 10); // 容量为10

  assert(a.get(0).value() == 1);
  assert(a.get(1).value() == 2);
  assert(a.get(2).value() == 3);
}

void TEST_2() { // 测试add函数，支持泛型
  ArrayList<float> a;
  a.add(1.5);
  a.add(2.33);
  a.add(3.45);
  float sum = a.get(0).value() + a.get(1).value() * a.get(2).value();
  assert(sum > 9.5 && sum < 9.9);
  assert(a.getSize() == 3);
  a.add(3.55);
  assert(a.getSize() == 4);
}

void TEST_3() { // 测试remove函数
  ArrayList<int> a;
  a.add(10);
  a.add(20);
  a.add(30);
  a.remove(40);
  a.remove(20);
  assert(a.getSize() == 2);
  assert(a.get(0).value() == 10);
  assert(a.get(1).value() == 30);

  a.remove(10);
  assert(a.getSize() == 1);
  assert(a.get(0).value() == 30);

  a.remove(30);
  assert(a.getSize() == 0);
}

void TEST_4() { // 测试get函数
  ArrayList<int> a;
  a.add(100);
  a.add(200);

  // 有效索引
  assert(a.get(0).value() == 100);
  assert(a.get(1).value() == 200);

  // 无效索引
  assert(a.get(2) == std::nullopt);
  assert(a.get(-1) == std::nullopt);
}

void TEST_5() { // 测试扩容
  ArrayList<int> a;
  for (int i = 0; i < 100; ++i) {
    a.add(i);
  }
  assert(a.getSize() == 100);
  assert(a.getCapacity() == 109);

  for (int i = 0; i < 100; ++i) {
    assert(a.get(i).value() == i);
  }
  for (int i = 0; i < 100; ++i) {
    a.remove(i);
  }
  assert(a.getCapacity() == 109);
  assert(a.getSize() == 0);
  for (int i = 0; i < 109; ++i) {
    a.add(i);
  }
  assert(a.getCapacity() == 109);
  assert(a.getSize() == 109);
  a.add(10);
  assert(a.getCapacity() == 163);
  assert(a.getSize() == 110);
}

void TEST_6() {
  ArrayList<int> a;
  assert(a.getSize() == 0);
  assert(a.getCapacity() == 10); // 初始容量为10
  ArrayList<float> b;
  a.add(1);
  a.add(1);
  b.add(1.0);
  b.add(1.0);
  for (int i = 2; i <= 8; i++) {
    a.add(a.get(i - 2).value() + a.get(i - 1).value());
    b.add(b.get(i - 2).value() + b.get(i - 1).value());
  }
  assert(std::abs((float)a.get(8).value() - b.get(8).value()) < 1e-3);
  a.add(123);
  assert(a.getCapacity() == 10);
  a.add(123);
  assert(a.getCapacity() == 15);
  assert(a.getSize() == 11);
}

// === 部分通过标准输入输出隐藏的测试用例 ===
void TEST_7() {
  ArrayList<long long> a;
  int n, m;
  std::cin >> n;
  int x, y;
  for (int i = 0; i < n; i++) {
    std::cin >> x;
    a.add(x);
  }
  std::cout << a.getCapacity() << std::endl;
  assert(a.getSize() == n);
  std::cin >> m;
  for (int i = 0; i < m; i++) {
    std::cin >> x >> y;
    a.remove(x);
    std::cout << a.get(y).value() << std::endl;
  }
  assert(a.getSize() == n - m);
  assert(a.get(n - m) == std::nullopt);
}

void TEST_8() {
  ArrayList<std::string> a;
  ArrayList<int> b;
  int n, m, k;
  std::cin >> n >> m >> k;
  std::string s;
  for (int i = 0; i < n; i++) {
    std::cin >> s;
    a.add(s);
  }
  for (int i = 0; i < m; i++) {
    b.add(1);
    b.add(2);
  }
  for (int i = 0; i < k; i++) {
    b.remove(2);
  }
  std::string res = "";
  for (int i = 0; i < a.getSize(); i++) {
    res.append(a.get(i).value());
  }
  std::cout << res << std::endl;
  std::cout << b.getCapacity() << std::endl;
  std::cout << b.get(23).value() << std::endl;
}

void TEST_9() {
  ArrayList<float> a;
  int n, m;
  std::cin >> n >> m;
  a.add(99.99);
  std::cout << a.getCapacity() << std::endl;
  std::cout << a.getSize() << std::endl;
  for (int i = 0; i < n; i++) {
    a.add(1.0 * i);
  }
  std::cout << a.getCapacity() << std::endl;
  std::cout << a.getSize() << std::endl;
  for (int i = 0; i < m; i++) {
    a.add(1.0 * i);
  }
  std::cout << a.getCapacity() << std::endl;
  std::cout << a.getSize() << std::endl;
  ArrayList<std::string> b;
  b.add("hello");
  b.add("nihao");
  b.remove("hello");
  std::cout << b.get(0).value() << std::endl;
  assert(b.get(1) == std::nullopt);
}

void TEST_10() {
  ArrayList<int> a;
  int n, m;
  assert(a.getSize() == 0);
  assert(a.getCapacity() == 10); // 初始容量为10
  a.add(1);
  assert(a.getSize() == 1);
  assert(a.getCapacity() == 10);
  int x;
  std::cin >> n >> m;
  // 添加超出初始容量的元素，验证容量扩展
  for (int i = 0; i <= n; ++i) {
    std::cin >> x;
    a.add(x);
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> x;
    if (a.get(x).has_value()) {
      std::cout << a.get(x).value() << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
  a.remove(1);
  for (int i = 1; i <= m; i++) {
    std::cin >> x;
    if (a.get(x).has_value()) {
      std::cout << a.get(x).value() << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}
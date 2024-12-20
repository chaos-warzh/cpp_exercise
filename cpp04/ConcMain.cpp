//
// Created by DELL on 2024/12/19.
//
#include "Concurrency.h"
#include "Semaphore.h"
#include <atomic>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

bool checker(const std::string &s, int brackets_num, int max_depth) {
  int depth = 0;
  int max_depth_reached = 0;
  int left_count = 0;
  int right_count = 0;

  for (char c : s) {
    if (c == '(') {
      ++depth;
      ++left_count;
      max_depth_reached = std::max(max_depth_reached, depth);
    } else if (c == ')') {
      --depth;
      ++right_count;
    }

    if (depth < 0 || max_depth_reached > max_depth) {
      return false;
    }
  }

  return depth == 0 && left_count == brackets_num && left_count == brackets_num;
}

// === TEST_CASES ===
void TEST_1();
void TEST_2();
void TEST_3();
void TEST_4();
void TEST_5();
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
          REGISTER_TEST_CASE(TEST_5),
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

extern int sum;
extern std::atomic<int> atomic_sum;
extern std::string brackets;

void TEST_1() {
  sum = 0;
  std::thread t1{slow_increment, 200000};
  std::thread t2{slow_increment, 100000};
  t1.join();
  t2.join();
  std::cout << sum << std::endl;
  assert(sum == 300000);
}

void TEST_2() {
  sum = 0;
  std::thread t1{slow_increment, 200000};
  std::thread t2{slow_increment, 200000};
  std::thread t3{slow_increment, 200000};
  t1.join();
  t2.join();
  t3.join();
  std::cout << sum << std::endl;
  assert(sum == 600000);
}

void TEST_3() {
  atomic_sum.store(0);
  std::thread t1{quick_increment, 200000, 10};
  std::thread t2{quick_increment, 300000, 5};
  t1.join();
  t2.join();
  std::cout << atomic_sum.load() << std::endl;
  init_sum(100);
  std::thread t3{quick_increment, 200000, 5};
  std::thread t4{quick_increment, 300000, 10};
  t3.join();
  t4.join();
  std::cout << atomic_sum.load() << std::endl;
  assert(atomic_sum.load() == 4000100);
}

void TEST_4() {
  brackets.clear();
  std::thread producer1{producer_thread, 50, 3};
  std::thread consumer1{consumer_thread, 50, 3};
  producer1.join();
  consumer1.join();
  std::cerr << brackets << std::endl; // 输出括号序列
  assert(checker(brackets, 50, 3));   // 检查括号是否符合要求
}

void TEST_5() {
  brackets.clear();
  std::thread producer1{producer_thread, 100, 1};
  std::thread consumer1{consumer_thread, 100, 1};
  producer1.join();
  consumer1.join();
  std::cerr << brackets << std::endl; // 输出括号序列
  assert(checker(brackets, 100, 1));  // 检查括号是否符合要求
}

void TEST_7() {
  brackets.clear();
  std::thread producer1{producer_thread, 2000, 20};
  std::thread consumer1{consumer_thread, 2000, 20};
  producer1.join();
  consumer1.join();
  std::cerr << brackets << std::endl;  // 输出括号序列
  assert(checker(brackets, 2000, 20)); // 检查括号是否符合要求
}

void TEST_8() {
  Semaphore mtx(1);
  int sum = 0;
  constexpr int times = 400000;

  auto increment = [&] {
    for (int i = 0; i < times; i++) {
      mtx.P();
      sum++;
      mtx.V();
    }
  };
  std::thread t1{increment};
  std::thread t2{increment};
  t1.join();
  t2.join();
  assert(sum == times * 2);
  std::cout << sum << std::endl;
}

void TEST_9() {
  Semaphore sem(2);
  std::mutex mtx;
  const int num_threads = 4;
  std::vector<std::thread> threads;
  std::vector<std::string> outputs;
  const std::string WAIT_FOR = "Wait for semaphere.";
  for (int i = 0; i < num_threads; ++i) {
    threads.emplace_back([&sem, &mtx, &outputs, i]() {
      sem.P();
      std::unique_lock<std::mutex> lock(mtx);
      outputs.push_back("do something: " + std::to_string(i) + ".");
    });
  }
  long long sum = 0;
  for (int i = 1; i <= 1000000; i++) {
    sum += i;
  }
  {
    std::unique_lock<std::mutex> lock(mtx);
    outputs.push_back(WAIT_FOR);
  }

  sem.V(); // 释放一个信号量
  sem.V(); // 再释放一个信号量

  for (auto &t : threads) {
    if (t.joinable()) {
      t.join();
    }
  }
  assert(outputs[3] != WAIT_FOR && outputs[4] != WAIT_FOR);
  std::cout << "Multiple threads test passed!" << std::endl;
}

void TEST_10() {
  const int num_philosophers = 5;
  Semaphore forks[num_philosophers] = {1, 1, 1, 1,
                                       1}; // 每个叉子用一个信号量表示

  auto philosopher = [&](int id) {
    int left_fork = id;
    int right_fork = (id + 1) % num_philosophers;

    if (id % 2 == 0) {
      forks[left_fork].P();
      forks[right_fork].P();
    } else {
      forks[right_fork].P();
      forks[left_fork].P();
    }

    forks[left_fork].V();
    forks[right_fork].V();
  };

  std::vector<std::thread> philosophers;
  for (int i = 0; i < num_philosophers; ++i) {
    philosophers.emplace_back(philosopher, i);
  }

  for (auto &t : philosophers) {
    t.join();
  }

  std::cout << "Dining philosophers test completed.\n";
}

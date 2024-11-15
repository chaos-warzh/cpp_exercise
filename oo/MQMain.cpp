//
// Created by DELL on 2024/11/14.
//
#include "MessageQueueManager.h"
#include <cassert>
#include <cstdlib>
#include <functional>

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

#define REGISTER_TEST_CASE(name) {#name, name}

int main() {
  std::unordered_map<std::string, std::function<void()>>
    test_functions_by_name = {
    REGISTER_TEST_CASE(TEST_1), REGISTER_TEST_CASE(TEST_2),
    REGISTER_TEST_CASE(TEST_3), REGISTER_TEST_CASE(TEST_4),
    REGISTER_TEST_CASE(TEST_5), REGISTER_TEST_CASE(TEST_6),
    REGISTER_TEST_CASE(TEST_7), REGISTER_TEST_CASE(TEST_8),
    REGISTER_TEST_CASE(TEST_9),
  };

  std::string test_case_name;
  std::cin >> test_case_name;
  auto it = test_functions_by_name.find(test_case_name);
  assert(it != test_functions_by_name.end());
  auto fn = it->second;
  fn();
  return 0;
}

void TEST_1() {
  Message m1 = {"hello, world!", 10};
  Message m2("I love NJU", 1);
  Message *m3 = new Message("I", 100);
  std::cout << m1.data << " " << m1.priority << std::endl;
  std::cout << m2.data << " " << m2.priority << std::endl;
  std::cout << m3->data << " " << m3->priority << std::endl;
  delete m3;
  m1.data[0] = 'd';
  m1.data[1] = 'e';
  std::cout << m1.data << " " << m1.priority << std::endl;
  const char *SCHOOL = "NJU";
  Message m4{SCHOOL, 50};
  std::cout << m4.data << " " << m4.priority << std::endl;
  m4.data[0] = 'Z';
  m4.priority = 60;
  std::cout << m4.data << " " << m4.priority << std::endl;
}

void TEST_2() {
  Message m1 = {"hello, world!", 10};
  char *pre_ptr = m1.data;
  Message m11 = std::move(m1);
  std::cout << (m11.data == pre_ptr) << std::endl;
  std::cout << m11.data << " " << m11.priority << std::endl;
  Message m2(std::move(m11));
  std::cout << (m2.data == pre_ptr) << std::endl;
  std::cout << m2.data << " " << m2.priority << std::endl;
}

void TEST_3() {
  Message m1 = {"hello, world!", 10};
  char *pre_ptr = m1.data;
  Message m11 = std::move(m1);
  m11.data[0] = 'H';
  std::cout << (m11.data == pre_ptr) << std::endl;
  std::cout << m11.data << " " << m11.priority << std::endl;
  Message m2 = {"nihao", 20};
  pre_ptr = m2.data;
  Message m21(std::move(m2));
  m21.data[0] = 'N';
  std::cout << (m21.data == pre_ptr) << std::endl;
  std::cout << m21.data << " " << m21.priority << std::endl;
}

void TEST_4() {
  Message m1 = {"hello, world!", 10};
  Message m2 = {"nihao, world", 20};
  std::cout << m1.data << " " << m1.priority << std::endl;
  char *pre_ptr_1 = m1.data;
  char *pre_ptr_2 = m2.data;
  m1 = std::move(m2);
  std::cout << m1.data << " " << m1.priority << std::endl;
  std::cout << (m1.data == pre_ptr_1) << std::endl;
  std::cout << (m1.data == pre_ptr_2) << std::endl;
  Message m3 = std::move(m1);
  std::cout << m3.data << " " << m3.priority << std::endl;
  std::cout << (m3.data == pre_ptr_1) << std::endl;
  std::cout << (m3.data == pre_ptr_2) << std::endl;
}

void TEST_5() {
  Message m1 = {"hello, world!", 10};
  char *pre_ptr = m1.data;
  Message m11 = std::move(m1);
  m11.data[0] = 'H';
  m11.priority = 15;
  std::cout << (m11.data == pre_ptr) << std::endl;
  std::cout << m11.data << " " << m11.priority << std::endl;
  Message m2 = {"nihao", 20};
  m2 = std::move(m11);
  m2.data[1] = 'E';
  ++m2.priority;
  std::cout << m2.data << " " << m2.priority << std::endl;
  m2 = std::move(m2);
  std::cout << m2.data << " " << m2.priority << std::endl;
}

void TEST_6() {
  MessageQueueManager manager;
  int priorities[] = {0, 45, 57, 34, 100, 78};
  for (int i = 1; i <= 5; ++i) {
    int priority = priorities[i];
    manager.addMessage(
      Message(("Message " + std::to_string(i)).c_str(), priority));
  }
  manager.printMessages();
}

void TEST_7() {
  MessageQueueManager manager;
  int priorities[] = {0, 45, 57, 34, 100, 78, 12, 35, 56, 99, 54, 1};
  for (int i = 1; i <= 11; ++i) {
    int priority = priorities[i];
    manager.addMessage(
      Message(("Message " + std::to_string(i)).c_str(), priority));
  }
  manager.printMessages();
  manager.addMessage({"hello, world", 15});
  manager.addMessage({"I love NJU", 80});
  manager.printMessages();
  MessageQueueManager manager2;
  int priorities2[] = {0, 5, 4, 3, 2, 1};
  for (int i = 1; i <= 5; ++i) {
    int priority = priorities[i];
    manager2.addMessage(
      Message(("Message " + std::to_string(i)).c_str(), priority));
  }
  manager2.printMessages();
}

void TEST_8() {
  MessageQueueManager manager;
  int priorities[] = {0, 45, 57, 34, 100, 78};
  for (int i = 1; i <= 5; ++i) {
    int priority = priorities[i];
    manager.addMessage(
      Message(("Message " + std::to_string(i)).c_str(), priority));
  }

  std::cout << "\nOriginal MessageQueueManager:" << std::endl;
  manager.printMessages();

  std::cout << "\nMoving manager to anotherManager:\n";
  MessageQueueManager anotherManager = std::move(manager);

  std::cout << "\nMessages in anotherManager:" << std::endl;
  anotherManager.printMessages();

  std::cout << "\nExiting Test:\n";
}

void TEST_9() {
  MessageQueueManager manager;
  int priorities[] = {0, 58, 57, 34, 98, 28};
  for (int i = 1; i <= 5; ++i) {
    int priority = priorities[i];
    manager.addMessage(
      Message(("Message " + std::to_string(i)).c_str(), priority));
  }

  std::cout << "\nOriginal MessageQueueManager:" << std::endl;
  manager.printMessages();

  std::cout << "\nMoving manager to anotherManager:\n";
  MessageQueueManager anotherManager;
  anotherManager.addMessage({"I love NJU!", 20});
  anotherManager = std::move(manager);

  std::cout << "\nMessages in anotherManager:" << std::endl;
  anotherManager.printMessages();
  anotherManager = std::move(anotherManager);
  anotherManager.printMessages();
  std::cout << "\nExiting Test:\n";
}
//
// Created by DELL on 2024/11/14.
//

#include "MessageQueueManager.h"


// 构造函数：初始化消息数据和优先级
Message::Message(const char *d, int p) : priority(p) {
  // 动态分配内存并复制消息内容
  data = new char[std::strlen(d) + 1];
  std::strcpy(data, d);
}

// 移动构造函数：高效地转移其他 Message 对象的所有权
Message::Message(Message &&other) noexcept : data(other.data), priority(other.priority) {
  other.data = nullptr; // 转移所有权后将源对象的指针置为 nullptr
}

// 移动赋值运算符：高效地转移其他 Message 对象的所有权
Message& Message::operator=(Message &&other) noexcept {
  if (this != &other) { // 防止自赋值
    delete[] data; // 释放当前对象的数据

    // 转移数据
    data = other.data;
    priority = other.priority;

    // 将源对象置空，表示其所有权已转移
    other.data = nullptr;
  }
  return *this;
}

// 析构函数：释放动态分配的消息内容
Message::~Message() {
  delete[] data;
}

// MessageQueueManager 类的实现

// 默认构造函数
MessageQueueManager::MessageQueueManager() {}

// 添加消息并按优先级顺序插入
void MessageQueueManager::addMessage(Message m) {
  // 找到插入位置，保持优先级顺序
  auto it = std::lower_bound(messages.begin(), messages.end(), m.priority, [](const Message& msg, int prio) {
    return msg.priority < prio;
  });

  // 插入新消息到正确位置，使用 std::move 进行高效转移
  messages.insert(it, std::move(m));
}

// 移动构造函数：高效转移其他 MessageQueueManager 对象的消息
MessageQueueManager::MessageQueueManager(MessageQueueManager &&other) noexcept : messages(std::move(other.messages)) {}

// 移动赋值运算符：高效转移其他 MessageQueueManager 对象的消息
MessageQueueManager& MessageQueueManager::operator=(MessageQueueManager &&other) noexcept {
  if (this != &other) { // 防止自赋值
    messages = std::move(other.messages);
  }
  return *this;
}

// 打印消息队列
void MessageQueueManager::printMessages() const {
  for (const auto &msg : messages) {
    std::cout << "Message: " << msg.data << ", Priority: " << msg.priority << std::endl;
  }
}

// 析构函数：仅输出信息，向用户表明对象的析构顺序
MessageQueueManager::~MessageQueueManager() {
  std::cout << "Destructing MessageQueueManager" << std::endl;
}

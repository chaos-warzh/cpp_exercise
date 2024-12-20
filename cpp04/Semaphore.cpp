//
// Created by DELL on 2024/12/19.
//

#include "Semaphore.h"

Semaphore::Semaphore(int count) : count(count) {};

void Semaphore::P() {
  std::unique_lock<std::mutex> lock(mutexS);
  while (count <= 0) {
    cvS.wait(lock);
  }
  count--;
}

void Semaphore::V() {
  std::unique_lock<std::mutex> lock(mutexS);
  count++;
  cvS.notify_one();
  lock.unlock();
}

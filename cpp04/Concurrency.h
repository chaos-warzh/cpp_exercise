//
// Created by DELL on 2024/12/19.
//
#ifndef CONCURRENCY_H
#define CONCURRENCY_H

// Task 1
void init_sum(int value);
void slow_increment(int times);
void quick_increment(int times, int v);

// Task 2
void producer_thread(int times, int k);
void consumer_thread(int times, int k);

#endif // CONCURRENCY_H
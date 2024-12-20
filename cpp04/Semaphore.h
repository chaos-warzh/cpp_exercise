//
// Created by DELL on 2024/12/19.
//

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <condition_variable>
#include <mutex>
class Semaphore {
    // TODO
    private:
        int count;

    public:
        Semaphore(int count) : count(count) {};
        void P();
        void V();
};

#endif //SEMAPHORE_H

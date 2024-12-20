#include <iostream>

class TaskQueue { // singleton
public:
    TaskQueue(const TaskQueue&) = delete;
    TaskQueue& operator=(const TaskQueue&) = delete;

    static TaskQueue& getInstance() {
        return instance;
    }

    void addTask(const std::string& task) {
        std::cout << "Task added: " << task << std::endl;
    }

    void processTasks() {
        std::cout << "Processing tasks..." << std::endl;
    }

private:
    TaskQueue() = default;

    static TaskQueue instance;

};

// static member definition must be outside the class!
TaskQueue TaskQueue::instance;


int main() {
    TaskQueue& taskQueue = TaskQueue::getInstance();
    taskQueue.addTask("Task 1");
    taskQueue.addTask("Task 2");
    taskQueue.processTasks();
    return 0;
}

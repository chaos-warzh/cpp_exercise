#include<iostream>

using namespace std;

class Integer {
public:
    // constructor
    Integer(int value) : value(value) {}

    // copy constructor
    Integer(const Integer &other) : value(other.value) {}

    // move constructor
    Integer(Integer &&other) : value(other.value) {}

    ~Integer() = default;

private:
    int value;
};

int main() {
    int a = 1;
    Integer int_a(a);
    Integer int_b(int_a);
    Integer int_c(std::move(int_a));
    return 0;
}
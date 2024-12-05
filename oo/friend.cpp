//
// Created by DELL on 2024/12/5.
//
#include <iostream>
#include <string>

class PersonA {
private:
    std::string secret = "I'm A";

public:
    friend class PersonB;
    void showB(PersonB &b) const;
};

class PersonB {
private:
    std::string secret = "I'm B";

public:
    friend class PersonA;
    void showA(PersonA &a) const {
        std::cout << a.secret << std::endl;
    }
    friend void can_show_b(const PersonB &b);
};

void PersonA::showB(PersonB &b) const {
    std::cout << b.secret << std::endl;
}

void can_show_b(const PersonB &b) {
    std::cout << b.secret << std::endl;
    // is not friend of A (not trasitive!)
}

int main() {
    return 0;
}
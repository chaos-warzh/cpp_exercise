//
// Created by DELL on 2024/10/13.
//
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class BFInterpreter {
private:
    vector<uint8_t> data;  // memory for BF program
    int pointer;
    string program;        // BF program
    int program_length;
    int cmd_index;         // index of current command
    stack<int> loop_stack; // handle `[` and `]`

    const int MEMORY_SIZE = 5000;

public:
    inline explicit BFInterpreter(const string &program) : program(program), pointer(0), cmd_index(0) {
        data.resize(MEMORY_SIZE, 0);  // init array size 1000 , set 0
        program_length = program.size();
    }

    ~BFInterpreter() = default;

    void run() {
        while (cmd_index < program_length) {
            char cmd = program[cmd_index];

            switch (cmd) {
                case '>':
                    pointer = (pointer + 1) % MEMORY_SIZE;  // 向右移动指针，循环数组
                    break;
                case '<':
                    pointer = (pointer - 1 + MEMORY_SIZE) % MEMORY_SIZE;  // 向左移动指针，循环数组
                    break;
                case '+':
                    data[pointer]++;
                    break;
                case '-':
                    data[pointer]--;
                    break;
                case '.':
                    cout << static_cast<char>(data[pointer]); // cout as ASCII
                    break;
                case ',':
                    readInput();
                    break;
                case '[':
                    if (data[pointer] == 0) {
                        jumpToMatchingBracket();
                    } else {
                        loop_stack.push(cmd_index);
                    }
                    break;
                case ']':
                    if (data[pointer] != 0) {
                        cmd_index = loop_stack.top();
                    } else {
                        loop_stack.pop();
                    }
                    break;
            }
            cmd_index++;
        }
    }

private:
    void readInput() {
        char c;
        if (cin.get(c)) {
            data[pointer] = static_cast<uint8_t>(c);
        } else {
            data[pointer] = 0;
        }
    }

    void jumpToMatchingBracket() {
        int open_brackets = 1;
        while (open_brackets > 0) {
            cmd_index++;
            if (cmd_index >= program_length) break;

            if (program[cmd_index] == '[') open_brackets++;
            if (program[cmd_index] == ']') open_brackets--;
        }
    }
};

int main() {
    string bf_program;
    getline(cin, bf_program);

    BFInterpreter interpreter(bf_program);
    interpreter.run();
    return 0;
}

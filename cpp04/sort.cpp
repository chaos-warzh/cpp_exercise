//
// Created by DELL on 2024/12/12.
//
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstddef>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

size_t N;

vector<string> inputs;
int main() {
    cin >> N;

    getchar();
    while (N-- > 0) {
        string line;
        getline(cin, line);
        inputs.push_back(line);
    }

    cin >> N;
    while (N--) { // commands
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case '-': {
                sort(inputs.begin(), inputs.end(), [](string a, string b) {return a < b;});
                break;
            }
            case 'n': {
                sort(inputs.begin(), inputs.end(), [](string a, string b) {return stoi(a) < stoi(b);});
                break;
            }
            case 'i': {
                sort(inputs.begin(), inputs.end(), [](string a, string b) {
                    transform(a.begin(), a.end(), a.begin(), ::tolower);
                    transform(b.begin(), b.end(), b.begin(), ::tolower);
                    return a < b;
                });
                break;
            }
            case 'd': {
                sort(inputs.begin(), inputs.end(), [](string a, string b) {
                    string new_a = "";
                    for (int i = 0; i < a.size(); ++i) {
                        if (a[i] == ' ' || isdigit(a[i]) || isalpha(a[i])) {
                            new_a += a[i];
                        }
                    }
                    string new_b = "";
                    for (int i = 0; i < b.size(); ++i) {
                        if (b[i] == ' ' || isdigit(b[i]) || isalpha(b[i])) {
                            new_b += b[i];
                        }
                    }

                    return new_a < new_b;
                });
                break;
            }
            case 'r': {
                sort(inputs.begin(), inputs.end(), [](string a, string b) {return a > b;});
                break;
            }
            default:
                return -1;
        }

        for (auto str : inputs) {
            cout << str << endl;
        }

    }
    return 0;
}
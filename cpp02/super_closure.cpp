//
// Created by DELL on 2024/10/13.
//

#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

#define N 100

int main() {
    int n;
    cin >> n;

    string R_input, S_input;
    cin >> R_input >> S_input;

    vector<vector<bool>> R(n, vector<bool>(n, false));
    vector<vector<bool>> S(n, vector<bool>(n, false));


    auto path = vector<vector<vector<bitset<N>>>>(n, vector<vector<bitset<N>>>(n, vector<bitset<N>>(0)));

// R_input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = i * n + j;
            R[i][j] = (R_input[idx] == '1');
        }
    }

// S_input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int idx = i * n + j;
            S[i][j] = (S_input[idx] == '1');
        }
    }

// super closure matrix T
    vector<vector<bool>> T(n, vector<bool>(n, false));

    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            for (int c = 0; c < n; ++c) {
                if (R[a][c] && S[c][b]) {
                    T[a][b] = true;
                    bitset<N> bs;
                    bs.set(c);
                    path[a][b].push_back(bs);
                    break;
                }
            }
        }
    }

    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            for (int c = 0; c < n; ++c) {
                if (T[b][a] && T[a][c]) {
                    // CHECK
                    for (const auto& pathBA : path[b][a]) {
                        for (const auto& pathAC : path[a][c]) {
                            bitset<N> newPath = pathBA | pathAC;
                            if ((pathBA & pathAC).none() && (!newPath[a])) {
                                newPath.set(a);
                                path[b][c].push_back(newPath);
                                T[b][c] = true;
                            }
                        }
                    }
                }
            }
        }
    }

// output in a binary string
    string result(n * n, '0');
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (T[i][j]) {
                result[i * n + j] = '1';
            }
        }
    }
    cout << result << endl;

    return 0;
}

//
// Created by DELL on 2024/12/7.
//
#include <stdio.h>

int board[9];
int coins[3];

int calc_score(int i, int j, int k) {
    if (i == j || i == k || j == k) { return -1; }
    int x1 = i / 3;
    int y1 = i % 3;
    int x2 = j / 3;
    int y2 = j % 3;
    int x3 = k / 3;
    int y3 = k % 3;
    int prdct = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (prdct == 0) { return -1;}
    return board[i] * coins[0] + board[j] * coins[1] + board[k] * coins[2];
}

int main() {
    int max_score = 0;

    for (int i = 0; i < 9; i++) {
        scanf("%d", &board[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%d", &coins[i]);
    }

    for (int i = 0; i < 9; i++) {
        // put coin 1 at position i
        for (int j = 0; j < 9; j++) {
            // put coin 2 at position j
            for (int k = 0; k < 9; k++) {
                // put coin 3 at position k
                int new_score = calc_score(i, j, k);
                max_score = new_score > max_score ? new_score : max_score;
            }
        }
    }

    printf("%d\n", max_score);
    return 0;
}
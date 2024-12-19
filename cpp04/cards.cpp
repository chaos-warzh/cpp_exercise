//
// Created by DELL on 2024/12/19.
//
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, k;
vector<int> cards;
int max_n = -1;

bool check(int max_sc) {
    // cards_num == k
    int k_cnt = 0;
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] <= max_sc) {
            // able
            k_cnt++;
            i++;
        }
    }

    if (k_cnt >= k) {
        return true;
    }
    return false;
}

int get_min() {
    // bserach [1 ... max_n]
    int min = 1;
    int max = max_n;
    // k cards need
    while (min < max) {
        int mid = ((min + max) >> 1);
        if (check(mid)) { // able for mid score
            max = mid;
        } else { // unable to have such a score
            min = mid + 1;
        }
    }
    return min;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int temp;
        scanf("%d", &temp);
        cards.push_back(temp);
        max_n = max(max_n, temp);
    }

    cout << get_min();
    return 0;
}

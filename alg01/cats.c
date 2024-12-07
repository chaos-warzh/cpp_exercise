//
// Created by DELL on 2024/12/7.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, R, hjm_M;
long long hjm_Days;

int hjm_days[(int)(1e8) + 5];

bool is_ok_l(int l) {
    int count = 0;
    long long days = 0;
    for (int i = 0; i <= N; i++) {
        if (hjm_days[i] > l && hjm_days[i] < R) { // is hjm
            count++;
            days += hjm_days[i] - l;
        }
    }
    if (count < hjm_M) return false;
    if (days < hjm_Days) return false;
    return true;
}

signed main() {
    // calc L 's max
    // hajimi >= M
    // Sigma i (x_i - L) >= D
    scanf("%d%d%d%lld", &N, &R, &hjm_M, &hjm_Days);

    for (int i = 0; i < N; i++) {
        scanf("%d", &hjm_days[i]);
    }

    // bsearch!!!
    // (left, R)
    int left = 0, right = R, ans = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (is_ok_l(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}

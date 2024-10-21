//
// Created by DELL on 2024/10/21.
//
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN ((int)(1E7))

bool canSatisfy(int n, double target, const vector<int>& fund, double k, int price) {
    double totalPurchase = 0;
    double remainingFund = 0;

    for (int i = 0; i < n; i++) {
        int bucketPurchase = fund[i] / price;
        totalPurchase += bucketPurchase;
        remainingFund += fund[i] - bucketPurchase * price;
    }

    double bulkPurchase = remainingFund / (price - k);
    totalPurchase += bulkPurchase;

    return totalPurchase >= target;
}

int main() {
    int n;
    double target, k;
    cin >> n >> target >> k;

    vector<int> fund(n);
    for (int i = 0; i < n; i++) {
        cin >> fund[i];
    }

    int left = 2, right = MAXN;
    int ans = -1;

    while (left <= right) {
        int mid = (left - right) / 2 + right;
        if (canSatisfy(n, target, fund, k, mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}
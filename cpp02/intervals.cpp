//
// Created by DELL on 2024/10/12.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int minTimeToCollectStamps(vector<pair<int, int>>& booths) {
    sort(booths.begin(), booths.end(), [](pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    });

    int currentPos = 0;
    int timeUnits = 0;
    int booth_N = booths.size();
    int idx = 0;

    while (idx < booth_N) {
        currentPos += 27;
        if (currentPos >= booths[idx].first) {
            if (booths[idx].second < currentPos) {
                currentPos = booths[idx].second;
            }
            idx++;
            timeUnits++;

            while (idx < booth_N && booths[idx].first <= currentPos) {
                if (booths[idx].second >= currentPos) idx++;
                else while (idx < booth_N && booths[idx].second <= currentPos) {
                // add all the booths that can be reached
                currentPos = booths[idx].second;
                idx++;
                }
            }
            
            
            while (idx < booth_N && booths[idx].first <= currentPos) {
                idx++;
            }
        } else { // need to go forward
            assert(idx < booth_N);
            timeUnits++;
        }
    }

    return timeUnits;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>>booths(n);

    int start, end;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &start, &end);
        booths[i] = {start, end};
    }

    int result = minTimeToCollectStamps(booths);
    printf("%dT\n", result);
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int minTimeToReachBottomRight(vector<vector<int>>& hills, int i, int j, int prevAltitude) {
    int n = hills.size();
    
    // Base case: if out of bounds or current altitude is higher than previous, return infinity
    if (i < 0 || i >= n || j < 0 || j >= n || hills[i][j] >= prevAltitude) {
        return INT_MAX;
    }
    
    // Base case: if at the bottom-right hill, return its altitude
    if (i == n - 1 && j == n - 1) {
        return hills[i][j];
    }
    
    // Recursive case: move right and down and choose the minimum time among them
    int rightTime = minTimeToReachBottomRight(hills, i, j + 1, hills[i][j]);
    int downTime = minTimeToReachBottomRight(hills, i + 1, j, hills[i][j]);
    
    // Return the minimum time plus the current hill's altitude
    return hills[i][j] + min(rightTime, downTime);
}

int main() {
    vector<vector<int>> hills1 = {{0, 1}, {4, 3}};
    cout << minTimeToReachBottomRight(hills1, 0, 0, INT_MAX) << endl;  // Output: 3

    vector<vector<int>> hills2 = {{0, 1, 2}, {3, 4, 9}, {10, 11, 6}};
    cout << minTimeToReachBottomRight(hills2, 0, 0, INT_MAX) << endl;  // Output: 9

    return 0;
}

#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
long long solution(const vector<long long> &s, const vector<long long> &t) {
    const int n = s.size();
    
    // Operations on the diff array
    // (a) +1 on position 0 and -1 on any position > 0
    // (b) +1 on any position
    
    long long last = 0, zero = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        const long long d = s[i] - t[i];
        if (d > 0) {
            return -1;
        }
        const long long diff = d - last;
        if (diff == 0) {
            continue;
        }
        if (i == 0) {
            zero = diff;
        } 
        else if (diff > 0) {
            zero += diff;
            if (zero > 0) {
                return -1;
            }
            r += diff; 
        } 
        else { // diff < 0
            r -= diff;
        }
        last = d;
    }
    return r - zero;
}

int main() {
    cout << solution({1, 2, 2}, {2, 2, 3}) << endl;
    cout << solution({1, 2, 3, -1, 0}, {3, 4, 3, 0, 4}) << endl;
    return 0;
}
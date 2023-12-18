#include <iostream>
#include <vector>

int countSubarraysWithMinMax(const std::vector<int>& price, int max_price, int min_price) {
    int n = price.size();
    int count = 0;
    int left = 0; // Left pointer for the sliding window
    
    for (int right = 0; right < n; ++right) {
        if (price[right] > max_price || price[right] < min_price) {
            // Reset left pointer and start a new potential subarray
            left = right + 1;
        } else {
            // Valid subarray found; count the subarrays ending at 'right'
            count +=1;
        }
    }
    
    return count;
}

int main() {
    int n = 4;
    std::vector<int> price = {1,2,3,2,4,2,3};
    int max_price = 3;
    int min_price = 2;

    int output = countSubarraysWithMinMax(price, max_price, min_price);
    std::cout << output << std::endl;  // Output should be 3

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        int total = 0, curr = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                curr = curr + 1;   // extend previous + new slice
                total += curr;
            } else {
                curr = 0;  // reset
            }
        }
        return total;
    }
};

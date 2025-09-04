#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int> points(n+1, 0);
        
        for (int x : nums) {
            points[x] += x; // accumulate value of taking x
        }
        
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = points[1];
        
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + points[i]);
        }
        
        return dp[n];
    }
};

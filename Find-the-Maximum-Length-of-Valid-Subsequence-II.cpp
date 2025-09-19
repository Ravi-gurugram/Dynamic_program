class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // dp[r1][r2] = max length of valid subsequence that ends with remainder r1,
        // and second-last remainder r2
        vector<vector<int>> dp(k, vector<int>(k, 0));
        int ans = 0;

        for (int num : nums) {
            int rem = num % k;
            // For each possible previous remainder
            for (int prev = 0; prev < k; prev++) {
                // We can extend a subsequence that ended with (prev, rem)
                // by adding this num, making new ending (rem, prev)
                int candidate = dp[prev][rem] + 1;
                dp[rem][prev] = max(dp[rem][prev], candidate);
                ans = max(ans, dp[rem][prev]);
            }
        }

        return ans;
    }
};
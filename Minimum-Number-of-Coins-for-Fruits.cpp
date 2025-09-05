class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        // dp[i] = minimum coins needed to obtain fruits starting from index i (0-indexed)
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;  // Base: no more fruits to buy → 0 coins

        for (int i = n - 1; i >= 0; --i) {
            // If you buy the i-th fruit (1-indexed as i+1), you can skip up to next i+1 fruits
            int maxNext = min((i + 1) * 2, n);
            for (int j = i + 1; j <= maxNext; ++j) {
                dp[i] = min(dp[i], prices[i] + dp[j]);
            }
        }

        return dp[0];
    }
};

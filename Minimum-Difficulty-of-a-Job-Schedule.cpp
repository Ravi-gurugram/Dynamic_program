
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1; // Not enough jobs to split into d days

        // dp[day][i] = minimum difficulty to schedule first i jobs in 'day' days
        vector<vector<int>> dp(d + 1, vector<int>(n + 1, INT_MAX));
        dp[0][0] = 0;

        for (int day = 1; day <= d; day++) {
            for (int i = day; i <= n; i++) {
                int maxd = 0;
                // Partition jobs: last part from j to i-1
                for (int j = i - 1; j >= day - 1; j--) {
                    maxd = max(maxd, jobDifficulty[j]);
                    if (dp[day - 1][j] != INT_MAX) {
                        dp[day][i] = min(dp[day][i], dp[day - 1][j] + maxd);
                    }
                }
            }
        }
        return dp[d][n];
    }
};
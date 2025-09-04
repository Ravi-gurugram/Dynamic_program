class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> directions = {{-1, 1}, {0, 1}, {1, 1}};

    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (dp[i][j] != -1) return dp[i][j];

        int maxMoves = 0;
        for (auto& dir : directions) {
            int ni = i + dir[0], nj = j + dir[1];
            if (ni >= 0 && ni < m && nj < n && grid[ni][nj] > grid[i][j]) {
                maxMoves = max(maxMoves, 1 + dfs(ni, nj, grid));
            }
        }
        return dp[i][j] = maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.assign(m, vector<int>(n, -1));

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            ans = max(ans, dfs(i, 0, grid));  // start from column 0
        }
        return ans;
    }
};

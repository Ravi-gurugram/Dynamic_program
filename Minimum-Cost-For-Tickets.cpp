#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, 0); // dp[i] = min cost to cover days[i..end]

        for (int i = n-1; i >= 0; i--) {
            // Option 1: 1-day pass
            int cost1 = costs[0] + dp[i+1];
            
            // Option 2: 7-day pass
            int j = i;
            while (j < n && days[j] < days[i] + 7) j++;
            int cost7 = costs[1] + dp[j];

            // Option 3: 30-day pass
            int k = i;
            while (k < n && days[k] < days[i] + 30) k++;
            int cost30 = costs[2] + dp[k];

            dp[i] = min({cost1, cost7, cost30});
        }

        return dp[0];
    }
};

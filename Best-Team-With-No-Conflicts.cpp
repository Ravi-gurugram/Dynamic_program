#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> players;
        for (int i = 0; i < n; i++) {
            players.push_back({ages[i], scores[i]});
        }
        
        // sort by age, then score
        sort(players.begin(), players.end());
        
        vector<int> dp(n, 0);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            dp[i] = players[i].second; // base case: team with only i
            for (int j = 0; j < i; j++) {
                if (players[j].second <= players[i].second) {
                    dp[i] = max(dp[i], dp[j] + players[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        if (power.empty()) return 0LL;

        // 1) frequency map
        unordered_map<int,long long> freq;
        freq.reserve(power.size()*2);
        for (int x : power) freq[x]++;

        // 2) sorted unique values
        vector<int> vals;
        vals.reserve(freq.size());
        for (auto &p : freq) vals.push_back(p.first);
        sort(vals.begin(), vals.end());

        int n = (int)vals.size();

        // 3) damage for each unique value
        vector<long long> dmg(n);
        for (int i = 0; i < n; ++i) dmg[i] = 1LL * vals[i] * freq[vals[i]];

        // 4) precompute next[i] = first index j > i with vals[j] > vals[i] + 2
        vector<int> next(n);
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (j < i + 1) j = i + 1;
            while (j < n && vals[j] <= vals[i] + 2) ++j;
            next[i] = j;
        }

        // 5) bottom-up DP: dp[i] = max damage from i..n-1
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            long long skip = dp[i + 1];
            long long take = dmg[i] + dp[next[i]];
            dp[i] = max(skip, take);
        }

        return dp[0];
    }
};

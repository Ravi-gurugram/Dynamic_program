#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;
        int ans = 1;

        for (string word : words) {
            dp[word] = 1;  // minimum chain is itself
            for (int i = 0; i < word.size(); i++) {
                string prev = word.substr(0, i) + word.substr(i+1);
                if (dp.count(prev)) {
                    dp[word] = max(dp[word], dp[prev] + 1);
                }
            }
            ans = max(ans, dp[word]);
        }
        return ans;
    }
};


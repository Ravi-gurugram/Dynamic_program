
class Solution {
public:
    int hammingDist(const string &a, const string &b) {
        int diff = 0;
        int len = a.size();
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) {
                diff++;
                if (diff > 1) return diff;  // early exit
            }
        }
        return diff;
    }
    
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), prev_idx(n, -1);
        int bestLen = 1;
        int bestEnd = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (groups[i] == groups[j]) continue;
                if (words[i].size() != words[j].size()) continue;
                if (hammingDist(words[i], words[j]) != 1) continue;
                
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev_idx[i] = j;
                }
            }
            if (dp[i] > bestLen) {
                bestLen = dp[i];
                bestEnd = i;
            }
        }
        
        // Reconstruct the subsequence
        vector<string> result;
        int cur = bestEnd;
        while (cur != -1) {
            result.push_back(words[cur]);
            cur = prev_idx[cur];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];   // sort by ending
        });
        int ans = 0, currEnd = INT_MIN;
        for (auto &p : pairs) {
            if (p[0] > currEnd) {
                ans++;
                currEnd = p[1];
            }
        }
        return ans;
    }
};

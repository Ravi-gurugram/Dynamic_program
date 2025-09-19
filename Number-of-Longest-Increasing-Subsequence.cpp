class Solution {
public:
    int n;
    vector<int> nums;
    vector<int> dpLen, dpCnt;

    pair<int,int> solve(int i) {
        if (dpLen[i] != -1) return {dpLen[i], dpCnt[i]};

        int bestLen = 1, ways = 1; // LIS starting here
        for (int j = i+1; j<n; j++) {
            if (nums[j] > nums[i]) {
                auto [nextLen, nextCnt] = solve(j);
                if (1 + nextLen > bestLen) {
                    bestLen = 1 + nextLen;
                    ways = nextCnt;          // new best
                } else if (1 + nextLen == bestLen) {
                    ways += nextCnt;         // another path
                }
            }
        }
        dpLen[i] = bestLen;
        dpCnt[i] = ways;
        return {bestLen, ways};
    }

    int findNumberOfLIS(vector<int>& arr) {
        nums = arr;
        n = nums.size();
        dpLen.assign(n, -1);
        dpCnt.assign(n, -1);

        int LIS = 0, ans = 0;
        for (int i=0; i<n; i++) {
            auto [len, cnt] = solve(i);
            if (len > LIS) {
                LIS = len;
                ans = cnt;
            } else if (len == LIS) {
                ans += cnt;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int solve(int i, int prev, vector<int>& arr1, vector<int>& arr2,
              unordered_map<long long,int>& dp) {
        if (i == arr1.size()) return 0;

        long long key = ((long long)i << 32) | prev; 
        if (dp.count(key)) return dp[key];

        int ans = 1e9;

        // Option 1: Keep arr1[i] if valid
        if (arr1[i] > prev) {
            ans = min(ans, solve(i+1, arr1[i], arr1, arr2, dp));
        }

        // Option 2: Replace arr1[i] with next greater in arr2
        auto it = upper_bound(arr2.begin(), arr2.end(), prev);
        if (it != arr2.end()) {
            ans = min(ans, 1 + solve(i+1, *it, arr1, arr2, dp));
        }

        return dp[key] = ans;
    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        unordered_map<long long,int> dp;
        int res = solve(0, -1, arr1, arr2, dp);
        return res >= 1e9 ? -1 : res;
    }
};
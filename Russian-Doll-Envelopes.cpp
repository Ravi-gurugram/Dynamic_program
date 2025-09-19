class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort by width asc, height desc if width same
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) return a[1] > b[1];
                 return a[0] < b[0];
             });

        // Step 2: Extract heights
        vector<int> heights;
        for (auto &e : envelopes) heights.push_back(e[1]);

        // Step 3: LIS on heights
        vector<int> lis;
        for (int h : heights) {
            auto it = lower_bound(lis.begin(), lis.end(), h);
            if (it == lis.end()) lis.push_back(h);
            else *it = h;
        }
        return lis.size();
    }
};
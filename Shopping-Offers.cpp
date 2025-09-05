#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> memo;

    // helper: convert needs to string for memoization key
    string encode(vector<int>& needs) {
        string key = "";
        for (int n : needs) key += to_string(n) + ",";
        return key;
    }

    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        string key = encode(needs);
        if (memo.count(key)) return memo[key];

        // cost without any special offers
        int cost = 0;
        for (int i = 0; i < needs.size(); i++) {
            cost += needs[i] * price[i];
        }

        // try each special offer
        for (auto& offer : special) {
            vector<int> newNeeds(needs.size());
            bool valid = true;
            for (int i = 0; i < needs.size(); i++) {
                if (offer[i] > needs[i]) {  // can't use this offer
                    valid = false;
                    break;
                }
                newNeeds[i] = needs[i] - offer[i];
            }
            if (valid) {
                cost = min(cost, offer.back() + dfs(price, special, newNeeds));
            }
        }

        return memo[key] = cost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(price, special, needs);
    }
};

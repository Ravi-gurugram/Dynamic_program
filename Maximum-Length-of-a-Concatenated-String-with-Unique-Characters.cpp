
class Solution {
public:
    int maxLen = 0;

    void backtrack(vector<int>& masks, vector<int>& lens, int idx, int curMask, int curLen) {
        maxLen = max(maxLen, curLen);

        for (int i = idx; i < masks.size(); i++) {
            if ((curMask & masks[i]) == 0) { // no conflict
                backtrack(masks, lens, i + 1, curMask | masks[i], curLen + lens[i]);
            }
        }
    }

    int maxLength(vector<string>& arr) {
        vector<int> masks;
        vector<int> lens;

        for (string& s : arr) {
            int mask = 0;
            bool valid = true;
            for (char c : s) {
                int bit = c - 'a';
                if (mask & (1 << bit)) { // duplicate char in same string
                    valid = false;
                    break;
                }
                mask |= (1 << bit);
            }
            if (valid) {
                masks.push_back(mask);
                lens.push_back(s.size());
            }
        }

        backtrack(masks, lens, 0, 0, 0);
        return maxLen;
    }
};
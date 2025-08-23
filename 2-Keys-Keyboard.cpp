class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0; // already one 'A'
        int ans = 0;
        for (int d = 2; d <= n; d++) {
            while (n % d == 0) {  
                ans += d;  // add factor
                n /= d;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);

        if (n == 1) return 1;
        if (n == 2) return 2;

        dp[n] = 1;
        dp[n-1] = 2;

        int i = n-2;
        while(i >= 1) {
            dp[i] = dp[i+1] + dp[i+2];
            i--;
        }

        return dp[1];
    }
};

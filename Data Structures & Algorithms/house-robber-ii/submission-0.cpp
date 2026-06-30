class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        vector<int> dp1(n+1, 0);
        if (n==1) return nums[0];
        dp[0] = 0;
        dp1[0] = 0;
        dp[1] = nums[0];
        dp1[1] = 0;
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        for(int i = 2; i <= n; i++) {
            dp1[i] = max(dp1[i-2] + nums[i-1], dp1[i-1]);
        }

        return max(dp1[n], dp[n-1]);
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp (amount+1, INT_MAX);

        sort(coins.begin(), coins.end(), greater<int>());

        dfs(coins, amount, dp);
        dp[0] = 0;

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

    int dfs(vector<int>& coins, int amount, vector<int>& dp) {
        int n = coins.size();
        if (amount == 0) return 0;
        if (dp[amount] != INT_MAX) {
            return dp[amount];
        }

        // cout<<"DFS: "<<amount<<'\n';

        for (int i = 0; i < n; i++) {
            if (amount < coins[i]) {
                continue;
            }
            int coinCount = 1;

            while (amount >= coinCount * coins[i]) {
                // cout<<"DFS inner: "<<coins[i]<<" Coins: "<<amount % coins[i]<<" coins: "<<amount / coins[i]<<'\n';
                int amt = dfs(coins, amount - coins[i]*coinCount, dp);
                if (amt > -1) {
                    amt = amt + coinCount;
                    dp[amount] = min(amt, dp[amount]);
                }
                coinCount++;
            }
        }
        dp[amount] = dp[amount] == INT_MAX ? -1 : dp[amount];
        return dp[amount];
    }
};

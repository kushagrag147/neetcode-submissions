class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int totalPalindromes = 0;

        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
            totalPalindromes++;
        }

        
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (j-i == 1) {
                    dp[i][j] = s[i] == s[j];
                    if (dp[i][j]) {
                        totalPalindromes++;
                    }
                } else {
                    dp[i][j] = dp[i+1][j-1] ? s[i] == s[j] :  false;
                    if (dp[i][j]) {
                        totalPalindromes++;
                    }
                }
            }
        }

        return totalPalindromes;
    }
};

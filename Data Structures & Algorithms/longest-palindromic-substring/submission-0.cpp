class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int maxPalindrome = 1;
        string result = "";

        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }

        
        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (j-i == 1) {
                    dp[i][j] = s[i] == s[j];
                    if (dp[i][j] && j-i+1 > maxPalindrome) {
                        maxPalindrome = j-i+1;
                        result = s.substr(i, j-i+1);
                    }
                    // maxPalindrome = dp[i][j] ? max(maxPalindrome, j-i+1) : maxPalindrome;
                } else {
                    dp[i][j] = dp[i+1][j-1] ? s[i] == s[j] :  false;
                    if (dp[i][j] && j-i+1 > maxPalindrome) {
                        maxPalindrome = j-i+1;
                        result = s.substr(i, j-i+1);
                    }
                    // maxPalindrome = dp[i][j] ? max(maxPalindrome, j-i+1) : maxPalindrome;
                }
            }
        }

        // cout<<maxPalindrome<<" "<<result;

        return maxPalindrome == 1 ? s.substr(0,1) : result;
    }
};

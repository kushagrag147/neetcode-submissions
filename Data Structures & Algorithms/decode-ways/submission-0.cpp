class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                bool isValid = checkIfCharValid(s.substr(i, 1));
                if (isValid) {
                    dp[i] = 1;
                } 
                // cout<<"DP: "<<i<<" value: "<<dp[i]<<"\n";
            } else {
                int isValid = checkIfCharValid(s.substr(i, 1));
                if (isValid) {
                    dp[i] = dp[i] + dp[i-1];
                }
                // cout<<"DP: "<<i<<" value: "<<dp[i]<<"\n";
                
                isValid = checkIfCharValid(s.substr(i-1, 2));
                if (isValid) {
                    dp[i] = dp[i] + (i <= 1 ? 1 : dp[i-2]);
                }
                // cout<<"DP: "<<i<<" value: "<<dp[i]<<"\n";
            }
        }

        return dp[n-1];
    }

    bool checkIfCharValid(string s) {
        int sInt = stoi(s);
        cout<<"String: "<<s<<" Number:"<<sInt<<" isValid:"<< (s[0] != '0' && sInt >= 1 && sInt <= 26)<<"\n";
        return s[0] != '0' && sInt >= 1 && sInt <= 26;
    }
};

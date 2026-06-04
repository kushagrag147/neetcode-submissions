class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(100,0);
        int maxLength = 0, curLength = 0, end = 0, start = 0;

        while(end < s.size()) {
            hash[s[end] - ' ']++;
            curLength++;
            if (hash[s[end] - ' '] == 1) {
                maxLength = max(curLength, maxLength);
            } else {
                while(hash[s[end] - ' '] > 1) {
                    hash[s[start] - ' ']--;
                    start++;
                    curLength--;
                }
            }
            end++;
        }

        return maxLength;

    }
};
 
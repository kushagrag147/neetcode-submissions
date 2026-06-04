class Solution {
public:
    int getMaxCharCount(vector<int>& freqCount) {
        int maxCount = 0;
        for (int freq: freqCount) {
            maxCount = max(maxCount, freq);
        }

        return maxCount;
    }

    int characterReplacement(string s, int k) {
        map<char, int> charSet;
        int left = 0, right=0, maxLength = 0;
        vector<int> freqCount(26,0);

        while (right < s.size()) {
            freqCount[s[right]-'A']++;
            int curStrSize = right - left + 1;
            if (curStrSize - getMaxCharCount(freqCount) > k) {
                cout<<curStrSize<<" "<<getMaxCharCount(freqCount)<<"\n";
                while (curStrSize - getMaxCharCount(freqCount) > k) {
                    freqCount[s[left]-'A']--;
                    left++;
                    curStrSize = right - left + 1;
                }
            }
            maxLength = max(curStrSize, maxLength);
            right++;
        }

        return maxLength;
    }


};

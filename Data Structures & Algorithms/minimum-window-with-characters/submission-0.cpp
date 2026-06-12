class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        unordered_map<char, int> countT, countS;
        int minLength = INT_MAX, start=0, resultStart=0;

        for(char c: t){
            countT[c]++;
        }

        int have =0, need= countT.size();
        for(int i =0; i<s.size(); i++) {
            countS[s[i]]++;

            if (countS[s[i]] == countT[s[i]]) {
                have++;
            }

            while(have == need) {
                if (i-start+1 < minLength) {
                    minLength = i-start+1;
                    resultStart = start;
                }
                minLength = min(minLength, i-start+1);
                countS[s[start]]--;

                if (countS[s[start]] < countT[s[start]]) {
                    have--;
                }
                start++;
            }
        }
        

        return minLength == INT_MAX ? "" : s.substr(resultStart, minLength);
    }
};

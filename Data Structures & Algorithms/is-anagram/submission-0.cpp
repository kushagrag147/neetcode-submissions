class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashMap(26,0);

        if (s.length() != t.length()) {
            return false;
        }

        for (int i =0; i < s.length(); i++) {
            hashMap[s[i] - 'a']++;
            hashMap[t[i] - 'a']--;
        }

        for(int i=0; i<26; i++){
            if (hashMap[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

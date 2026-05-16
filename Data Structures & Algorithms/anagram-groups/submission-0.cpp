class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> hashMap;
        vector<vector<string>> result;

        for(string str: strs) {
            vector<int> key(26, 0);
            for (char c: str) {
                key[c-'a']++;
            }
            hashMap[key].push_back(str);
        }

        for (const auto& [key, value] : hashMap) {
            // cout<< key << " " << value << "\n";
            result.push_back(value);
        }

        return result;
    }
};

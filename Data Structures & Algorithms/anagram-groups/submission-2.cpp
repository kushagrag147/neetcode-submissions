class Solution {
public:
    // 1. Define a custom hash logic for vector<int>
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t seed = 0;
        for (int i : v) {
            // Standard algorithm to combine hash values
            seed ^= hash<int>()(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHash> hashMap;
        vector<vector<string>> result;

        for(string str: strs) {
            vector<int> key(26, 0);
            for (char c: str) {
                key[c-'a']++;
            }
            hashMap[key].push_back(str);
        }

        for (auto it : hashMap) {
            // cout<< key << " " << value << "\n";
            result.push_back(it.second);
        }

        return result;
    }
};

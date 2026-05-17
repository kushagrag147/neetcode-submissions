class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(10005);
        unordered_map<int, int> freqHash;
        vector<int> result;

        for (int num: nums) {
            if (freqHash.find(num) == freqHash.end()) {
                freqHash[num] = 0;
            }
            freqHash[num]++;
        }

        for (auto it: freqHash) {
            buckets[it.second].push_back(it.first);
        }

        for (int i=buckets.size()-1; i>=0; i--){
            if (buckets[i].size() == 0){
                continue;
            }
            
            for (int num: buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    return result;
                }
            }
        }
    }
};

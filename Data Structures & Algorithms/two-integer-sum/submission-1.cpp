class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap {};
        for (int i=0; i<nums.size(); i++){
            if (hashMap.find(target - nums[i]) != hashMap.end()) {
                return vector<int>({hashMap.at(target-nums[i]), i});
            } else {
                if (hashMap.find(nums[i]) == hashMap.end()){
                    hashMap.insert({nums[i], i});
                }
            }
        }

        return vector<int>();
    }
};

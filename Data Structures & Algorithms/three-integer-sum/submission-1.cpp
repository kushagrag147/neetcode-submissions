class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<vector<int>, bool> hashMap;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++) {
            if (i>0 && nums[i-1] == nums[i]) {
                continue;
            }
            int targetSum = 0 - nums[i];
            int j =i+1, k=nums.size()-1;
            map<pair<int, int>, bool> hashMap;
            // cout<<targetSum<<"\n";
            while(j<k) {
                if (nums[j] + nums[k] == targetSum) {
                    if (hashMap.find(make_pair(nums[j], nums[k])) == hashMap.end()) {
                        result.push_back({nums[i], nums[j], nums[k]});
                        hashMap.insert({make_pair(nums[j], nums[k]), true});
                    } 
                    j++;
                    k--;
                } else if (nums[j] + nums[k] < targetSum) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return result;
    }
};

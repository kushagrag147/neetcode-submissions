class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> currNums;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // for(int i = 0; i < n; i++) {
            checkSum(nums, target, 0, currNums);
        // }
        
        return results;
    }

    void checkSum(vector<int>& nums, int target, int index, vector<int> currNum) {
        if (target==0) {
            results.push_back(currNum);
            return;
        }

        if (index >= nums.size() || target < 0) {
            return;
        }

        checkSum(nums, target, index+1, currNum);
        
        int tempTarget = target;
        tempTarget = target - nums[index];
        while(tempTarget >= 0) {
            currNum.push_back(nums[index]);
            checkSum(nums, tempTarget, index+1, currNum);
            tempTarget = tempTarget - nums[index];
        }
    }

    void print(vector<int>& nums) {
        for(int num: nums) {
            cout<<num<<" ";
        }
        cout<<"\n";
    }
};

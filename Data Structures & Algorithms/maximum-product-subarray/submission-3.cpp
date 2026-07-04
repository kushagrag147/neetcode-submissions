class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax= 1, curMin = 1, result = INT_MIN, n = nums.size();

        for(int i = 0; i < n; i++) {
            int temp = curMax;
            curMax = max(nums[i], max(nums[i] * curMax, nums[i] * curMin));
            curMin = min(nums[i], min(nums[i] * curMin, temp* nums[i]));

            result = max(result, curMax);
        }

        return result;
    }
};

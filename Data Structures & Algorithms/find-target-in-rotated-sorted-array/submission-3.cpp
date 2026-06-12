class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0, r =nums.size()-1;

        while(l<r) {
            int m = l + (r-l)/2;

            if (nums[m] < nums[r]) {
                r=m;
            } else {
                l=m+1;
            }
        }
        if (target >= nums[l] && target <= nums[nums.size()-1]) {
            r = nums.size()-1;
        } else {
            r=l;
            l=0;
        }

        while(l<=r) {
            int m = l + (r-l)/2;

            if (nums[m]==target) {
                return m;
            } else if (nums[m] > target) {
                r = m-1;
            } else {
                l=m+1;
            }
        }

        return -1;
    }
};

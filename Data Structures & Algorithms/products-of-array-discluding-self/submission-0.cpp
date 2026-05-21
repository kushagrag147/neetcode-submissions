class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long int product = 1;
        int noOfZeroes = 0;
        vector<int> output;
        for (int num: nums) {
            if (num == 0) {
                noOfZeroes++;
                continue;
            }
            product *= num;
        }
        for (int num: nums) {
            int lessProduct;
            if (num == 0) {
                lessProduct = noOfZeroes > 1 ? 0 : product;
            } else {
                lessProduct = noOfZeroes > 0 ? 0 : product / num;
            }
            output.push_back(lessProduct);
        }

        return output;
    }
};

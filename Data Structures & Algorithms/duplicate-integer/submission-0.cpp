class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int, bool> hashMap;

        for (int ele: nums) {
            if (hashMap.find(ele) == hashMap.end()) {
                hashMap.insert({ele, true});
            }else {
                return true;
            } 
        }

        return false;
    }
};
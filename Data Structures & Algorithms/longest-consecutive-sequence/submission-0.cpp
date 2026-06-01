class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> hashMap;
        vector<int> startNums;
        int maxLength = 0;
        for (int num: nums) {
            hashMap[num] = true;
            if (hashMap.find(num-1) == hashMap.end()) {
                startNums.push_back(num);
            }
        }

        for (int startNum: startNums) {
            int length = 1, itrNum=startNum+1;
            while(hashMap.find(itrNum) != hashMap.end()) {
                itrNum++;
                length++;
            }
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};

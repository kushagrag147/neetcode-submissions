class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0, j=heights.size()-1;
        int result = 0;
        while(i<j) {
            result = max(result, (j-i)*min(heights[i], heights[j]));
            
            if(heights[i] <= heights[j]) {
                i++;
            } else {
                j--;
            }
            
        }

        return result;
    }
};

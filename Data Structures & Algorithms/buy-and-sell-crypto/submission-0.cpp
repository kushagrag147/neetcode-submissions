class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxPrice = INT_MIN, maxProfit = 0;

        for (int price: prices) {
            minPrice = min(price, minPrice);
            maxProfit = max(price - minPrice, maxProfit);
        }
        // cout<<minPrice<<" "<<maxPrice<<" "<<maxProfit;

        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxProfit = 0;

        for (int price: prices) {
            minPrice = min(price, minPrice);
            maxProfit = max(price - minPrice, maxProfit);
        }

        return maxProfit;
    }
};

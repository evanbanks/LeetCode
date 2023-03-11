class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int max_profit = 0;
        for (size_t ws=0, we=0; we<prices.size(); ++we){
            max_profit = std::max(prices[we]-prices[ws],max_profit);
            if (prices[we] < prices[ws]) ws = we;
        }   
        return max_profit;
    }
};

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1 = 0;
        for (int i=0; i<prices.size(); ++i){
            if (prices[i] < prices[min1]) min1 = i;
        }
        int min2 = min1 ? 0 : 1;
        for (int i=0; i<prices.size(); ++i){
            if (i != min1 && prices[i] < prices[min2]) min2 = i;
        }
        int diff = money - prices[min1] - prices[min2];
        return diff >= 0 ? diff : money;
    }
};

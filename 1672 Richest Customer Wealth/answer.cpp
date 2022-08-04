#include <vector>

class Solution {
public:
    int maximumWealth(const std::vector<std::vector<int>>& accounts) {
        int max_wealth = 0;
        for (size_t i=0; i<accounts.size(); ++i){
            int wealth = 0;
            for (size_t j=0; j<accounts[i].size(); ++j){
                wealth += accounts[i][j];
            }
            max_wealth = std::max(max_wealth, wealth);
        }
        return max_wealth;
    }
};
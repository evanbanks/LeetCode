class Solution {
public:
    int minCostClimbingStairs(const std::vector<int>& cost) {
        int c2 = cost[0], c1 = cost[1], curr;
        for (int i=2; i<cost.size(); ++i){
            curr = cost[i] + std::min(c2,c1);
            c2 = c1;
            c1 = curr;
        }
        return std::min(c1,c2);
    }
};

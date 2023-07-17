class Solution {
public:
    int maximumScore(const std::vector<int>& nums, const std::vector<int>& multipliers) {
        std::vector<int> tab(multipliers.size()+1,0);
        for (int m = multipliers.size()-1; m >= 0; --m){
            for (int l=0; l<=m; ++l){
                tab[l] = std::max(nums[l]*multipliers[m]+tab[l+1],nums[nums.size()-1-(m-l)]*multipliers[m]+tab[l]);
            }
        }
        return tab[0];
    }
};

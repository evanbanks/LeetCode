class Solution {
public:
    int rob(const std::vector<int>& nums) {
        int h2 = 0, h1 = 0, curr;
        for (size_t i=0; i<nums.size(); ++i){
            curr = std::max(h1, h2 + nums[i]);
            h2 = h1;
            h1 = curr;
        }
        return curr;
    }
};

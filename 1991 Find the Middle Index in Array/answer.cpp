#include <vector>

class Solution {
public:
    int findMiddleIndex(const std::vector<int>& nums) {
        int l_sum = 0, r_sum = 0;
        for (size_t i=1; i<nums.size(); ++i){
            r_sum += nums[i];
        }
        for (size_t i=0; i<nums.size()-1; ++i){
            if (l_sum == r_sum){
                return i;
            }
            l_sum += nums[i];
            r_sum -= nums[i+1];
        }
        return l_sum == r_sum ? nums.size()-1 : -1;
    }
};
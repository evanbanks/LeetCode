#include <vector>

class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for (size_t i=nums.size()-1; i>1; --i){
            if (nums[i-2] + nums[i-1] > nums[i]){
                return nums[i-2]+nums[i-1]+nums[i];
            }
        }
        return 0;
    }
};
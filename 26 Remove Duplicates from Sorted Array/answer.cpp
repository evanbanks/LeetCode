#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        size_t next_non_dup = 1;
        for (size_t i=0; i<nums.size(); ++i){
            if (nums[next_non_dup-1] != nums[i]) nums[next_non_dup++] = nums[i];
        }
        return next_non_dup;
    }
};
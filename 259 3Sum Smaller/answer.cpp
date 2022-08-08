#include <vector>

class Solution {
public:
    int threeSumSmaller(std::vector<int>& nums, const int target) {
        std::sort(nums.begin(),nums.end());
        int count = 0;
        for (size_t i=0; i<nums.size(); ++i){
            if (nums[i] > 0 && nums[i] >= target) return count;
            size_t left = i+1, right = nums.size()-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target){
                    count += right-left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return count;
    }
};
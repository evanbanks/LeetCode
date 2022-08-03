#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, const int target) {
        int a = 0, b = nums.size()-1;
        while (a < b){
            if (nums[a] + nums[b] < target){
                ++a;
            } else if (nums[a] + nums[b] > target){
                --b;
            } else {
                return {a+1, b+1};
            }
        }
        return {-1,-1};
    }
};
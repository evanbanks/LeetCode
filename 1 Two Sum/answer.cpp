#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, const int target) {
        std::unordered_map<int,int> seen;
        for (int i=0; i<nums.size(); ++i){
            if (seen.find(target - nums[i]) != seen.end()){
                return {i, seen[target-nums[i]]};
            } else {
                seen[nums[i]] = i;
            }
        }
        return {0,0};
    }
};
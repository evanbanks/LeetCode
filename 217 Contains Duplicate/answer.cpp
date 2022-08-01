#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsDuplicate(const std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (size_t i=0; i<nums.size(); ++i){
            if (seen.find(nums[i]) != seen.end()){
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};
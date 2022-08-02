#include <vector>

class Solution {
public:
    int longestSubarray(const std::vector<int>& nums) {
        int max_length = 0, num_zero = 0;
        for (int ws=0, we=0; we<nums.size(); ++we){
            if (!nums[we]) ++num_zero;
            while (num_zero > 1){
                if (!nums[ws++]) --num_zero;
            }
            max_length = std::max(max_length, we-ws);
        }
        return max_length;
    }
};
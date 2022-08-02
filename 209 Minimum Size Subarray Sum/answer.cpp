#include <vector>

class Solution {
public:
    int minSubArrayLen(const int target, const std::vector<int>& nums) {
        int length = __INT32_MAX__, sum = 0;
        for (int ws=0, we=0; we<nums.size(); ++we){
            sum += nums[we];
            while (sum >= target){
                length = std::min(length, we-ws+1);
                sum -= nums[ws++];
            }
        }
        return length == __INT32_MAX__ ? 0 : length;
    }
};
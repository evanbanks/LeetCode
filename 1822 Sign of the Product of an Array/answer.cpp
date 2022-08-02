#include <vector>

class Solution {
public:
    int arraySign(const std::vector<int>& nums) {
        int sign = 1;
        for (const auto& n : nums){
            if (n){
                if (n>>31) sign *= -1;
            } else {
                return 0;
            }
        }
        return sign;
    }
};
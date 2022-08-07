#include <vector>

class Solution {
public:
    int findNumbers(const std::vector<int>& nums) {
        int count = 0;
        for (auto n : nums){
            bool is_even = true;
            while (n){
                is_even = !is_even;
                n /= 10;
            }
            count += is_even;
        }
        return count;
    }
};
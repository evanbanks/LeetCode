#include <vector>

class Solution {
public:
    int triangleNumber(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int ans = 0;
        for (int i=nums.size()-1; i>1; --i){
            int low = 0, high = i-1;
            while (low < high){
                if (nums[low] + nums[high] > nums[i]){
                    ans += high - low;
                    --high;
                } else {
                    ++low;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(const vector<int>& nums) {
        int ans = 0, curr = 0;
        for (int i=0; i<nums.size(); ++i) int a = nums[i] ? ans = std::max(ans,++curr) : curr = 0;
        return ans;
    }
};

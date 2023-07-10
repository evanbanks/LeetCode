class Solution {
    int dp(const int n, const std::vector<int>& nums, std::vector<int>& memo){
        if (n < 0) return 0;
        if (memo[n] < 0) memo[n] = std::max(dp(n-2,nums,memo)+nums[n],dp(n-1,nums,memo));
        return memo[n];
    }
public:
    int rob(const std::vector<int>& nums) {
        std::vector<int> memo(nums.size(),-1);
        return dp(nums.size()-1,nums,memo);
    }
};

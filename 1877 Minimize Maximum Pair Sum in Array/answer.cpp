class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int max_pair = 0;
        for (int i=0; i<nums.size()/2; ++i){
            max_pair = max(max_pair,nums[i]+nums[nums.size()-i-1]);
        }
        return max_pair;
    }
};

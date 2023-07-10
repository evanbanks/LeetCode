class Solution {
public:
    int longestSubarray(const std::vector<int>& nums) {
        int max_length = 0, last_zero = -1;
        for (int ws=0, we=0; we<nums.size(); ++we){
            if (!nums[we]){
                ws = last_zero + 1;
                last_zero = we;
            }
            max_length = std::max(max_length, we-ws);
        }
        return max_length;
    }
};

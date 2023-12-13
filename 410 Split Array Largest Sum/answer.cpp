class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        auto test = [&](int x){
            int r = k-1;
            int sum = 0;
            for (int i : nums){
                if (i > x) return false;
                if (sum + i > x){
                    --r;
                    sum = 0;
                }
                sum += i;
            }
            return r >= 0;
        };
        int left = *max_element(nums.begin(),nums.end()), right = accumulate(nums.begin(),nums.end(),0);
        while (left < right){
            int mid = (left + right) / 2;
            if (test(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};

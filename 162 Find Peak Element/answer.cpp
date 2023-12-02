class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right){
            int mid = (left + right + 1) / 2;
            if (nums[mid-1] > nums[mid]) right = mid - 1;
            else left = mid;
        }
        return left;
    }
};

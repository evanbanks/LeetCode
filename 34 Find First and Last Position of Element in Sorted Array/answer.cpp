class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v = {-1,-1};
        int left = 0, right = nums.size()-1;
        while (left < right){
          int mid = (left + right) / 2;
          if (nums[mid] >= target) right = mid;
          else left = mid + 1;
        }
        if (!nums.size() || nums[left] != target) return v;
        v[0] = left;
        left = 0; right = nums.size()-1;
        while (left < right){
          int mid = (left + right + 1) / 2;
          if (nums[mid] <= target) left = mid;
          else right = mid -1;
        }
        v[1] = right;
        return v;
    }
};

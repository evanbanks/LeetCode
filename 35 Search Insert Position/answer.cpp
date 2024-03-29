#include<vector>

class Solution {
public:
  int searchInsert(const std::vector<int>& nums, const int target) {
    int l = 0, r = nums.size()-1, mid;
    while (l <= r){
      mid = l+(r-l)/2;
      if (nums[mid] == target){
        return mid;
      } else if (nums[mid] > target){
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return l;
  }
};
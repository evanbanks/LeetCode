#include <vector>

class Solution {
public:
  std::vector<int> searchRange(const std::vector<int>& nums, const int target) {
    std::vector<int> interval = {-1,-1};
    int l = 0, r = nums.size()-1, mid;
    while (l <= r){
      mid = (l+r)/2;
      if (nums[mid] == target){
        interval[0] = mid;
        r = mid-1;
      } else if (nums[mid] > target){
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    l = 0;
    r = nums.size()-1;
    while (l <= r){
      mid = (l+r)/2;
      if (nums[mid] == target){
        interval[1] = mid;
        l = mid+1;
      } else if (nums[mid] > target){
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return interval;
  }
};

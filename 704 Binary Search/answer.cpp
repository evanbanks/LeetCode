#include <vector>

class Solution {
public:
  int search(const std::vector<int>& nums, const int target) {
    int l, r;
    l = 0;
    r = nums.size()-1;
    while (l<=r){
      int mid = l + (r-l);
      if (nums[mid] == target){
        return mid;
      } else if (nums[mid] > target){
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return -1;
  }
};
#include <vector>

using ll = long long;

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, const int target) {
        if (nums.size() < 4) return {};
        std::sort(nums.begin(),nums.end());
        std::vector<std::vector<int>> quadruplets;
        for (int i=0; i<nums.size()-3; ++i){
          if (i && nums[i] == nums[i-1]) continue;
          if (nums[i] > target/4) return quadruplets;
          for (int j=i+1; j<nums.size()-2; ++j){
            if (j > i+1 && nums[j] == nums[j-1]) continue;
            int left = j+1, right = nums.size()-1;
            while (left < right){
              ll difference = (ll)target - (ll)nums[i] - (ll)nums[j] - (ll)nums[left] - (ll)nums[right];
              if (difference > 0) ++left;
              else if (difference < 0) --right;
              else {
                quadruplets.push_back({nums[i],nums[j],nums[left],nums[right]});
                do {++left;} while (left < right && nums[left] == nums[left - 1]);
                do {--right;} while (left < right && nums[right] == nums[right + 1]);
              }
            }
          }
        }
        return quadruplets;
    }
};
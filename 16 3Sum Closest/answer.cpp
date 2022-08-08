#include <vector>
#include <limits>

class Solution {
public:
    int threeSumClosest(std::vector<int>& arr, const int target) {
        int min_diff = std::numeric_limits<int>::max();
        std::sort(arr.begin(),arr.end());
        for (int i=0; i<arr.size()-2; ++i){
          int left = i+1, right = arr.size()-1;
          while (left < right){
            int target_diff = target - arr[i] - arr[left] - arr[right];
            if (std::abs(target_diff) < std::abs(min_diff)){
              min_diff = target_diff;
              if (!min_diff) return target;
            } else if (target_diff < 0) --right;
            else ++left;
          }
        }
        return target - min_diff;
    }
};
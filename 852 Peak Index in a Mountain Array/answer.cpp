#include <vector>

class Solution {
public:
  int peakIndexInMountainArray(const std::vector<int>& arr) {
    int l = 1, r = arr.size()-2, mid;
    while (true){
      mid = (l+r)/2;
      if (arr[mid] > arr[mid+1]){
        if (arr[mid-1] < arr[mid]){
          return mid;
        } else {
          r = mid-1;
        }
      } else {
        l = mid+1;
      }
    }
  }
};

#include <vector>
#include <algorithm>

class Solution {
public:
  int findTheDistanceValue(const std::vector<int>& arr1, std::vector<int>& arr2, const int d) {
    std::sort(arr2.begin(),arr2.end());
    int l, r, dist = arr1.size();
    for (int i=0; i<arr1.size(); ++i){
      l = 0, r = arr2.size()-1;
      while (l<=r){
        int mid = (l+r)/2;
        if (std::abs(arr1[i]-arr2[mid]) <= d){
          --dist;
          break;
        } else if (arr1[i] > arr2[mid]){
          l = mid+1;
        } else {
          r = mid-1;
        }
      }
    }
    return dist;
  }
};

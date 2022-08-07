#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& arr) {
    std::vector<std::vector<int>> triplets;
    std::sort(arr.begin(),arr.end());
    for (size_t i=0; i<arr.size()-2; ++i){
      if (i && arr[i] == arr[i-1]) continue;
      int first = arr[i];
      if (first > 0) break;
      size_t left = i+1, right = arr.size()-1;
      while (left < right){
        int match = first+arr[left]+arr[right];
        if (!match){
          triplets.push_back({first,arr[left],arr[right]});
            left++;
            right--;
            while (left < right && arr[left] == arr[left - 1]) ++left;
            while (left < right && arr[right] == arr[right + 1]) --right;
        } else if (match > 0){
          --right;
        } else {
          ++left;
        }
      }
    }
    return triplets;
    }
};
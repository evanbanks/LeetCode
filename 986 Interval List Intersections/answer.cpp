#include <vector>
#include <algorithm>

class Solution {
public:
  std::vector<std::vector<int>> intervalIntersection(const std::vector<std::vector<int>>& l1, const std::vector<std::vector<int>>& l2) {
    std::vector<std::vector<int>> intersections;
    for (int i=0, j=0; i<l1.size() && j<l2.size();){
      int max_start = std::max(l1[i][0],l2[j][0]);
      int min_end = std::min(l1[i][1],l2[j][1]);
      if (max_start <= min_end){
        intersections.push_back({max_start,min_end});
      }
      if (l1[i][1] < l2[j][1]){
        ++i;
      } else {
        ++j;
      }
    }
    return intersections;
  }
};
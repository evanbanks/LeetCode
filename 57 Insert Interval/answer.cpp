#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> insert(const std::vector<std::vector<int>>& in, std::vector<int>& newIn) {
    std::vector<std::vector<int>> mi;
    size_t i = 0;
    for (; i<in.size(); ++i){
      if (in[i][1] < newIn[0]){
        mi.push_back(in[i]);
      } else if (in[i][0] <= newIn[1]){
        newIn[0] = std::min(newIn[0], in[i][0]);
        newIn[1] = std::max(newIn[1], in[i][1]);
      } else break;
    }
    mi.push_back(newIn);
    for (; i<in.size(); ++i){
      mi.push_back(in[i]);
    }
    return mi;
  }
};
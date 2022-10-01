#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> insert(const std::vector<std::vector<int>>& in, const std::vector<int>& newIn) {
    std::vector<std::vector<int>> mi;
    size_t i = 0;
    while (i < in.size() && in[i][0] < newIn[0]){
      mi.push_back(in[i++]);
    }
    if (!mi.size() || mi[mi.size()-1][1] < newIn[0]){
      mi.push_back(newIn);
    } else {
      mi[mi.size()-1][1] = std::max(mi[mi.size()-1][1],newIn[1]);
    }
    size_t j = mi.size()-1;
    for (; i<in.size(); ++i){
      if (mi[j][1] < in[i][0]){
        mi.push_back(in[i]);
        ++j;
      } else {
        mi[j][1] = std::max(mi[j][1], in[i][1]);
      }
    }
    return mi;
  }
};